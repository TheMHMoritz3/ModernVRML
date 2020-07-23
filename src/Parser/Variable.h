//
// Created by moritzh on 21.07.20.
//

#ifndef MODERNVRML_VARIABLE_H
#define MODERNVRML_VARIABLE_H

#include "IComponent.h"
#include <functional>
#include <vector>
namespace ModernVRML {
    namespace Parser {
        template<typename Type>
        class MatVariable : public IComponent {
        public:
            MatVariable() = default;
            MatVariable(std::string name, std::function<std::string(Type)> toString, size_t numberOfComponents);
            MatVariable(MatVariable<Type>& other);
            MatVariable<Type>& operator=(MatVariable<Type>& other);
            void setValue(size_t index, Type value);

            ComponentType componentType() override;

            std::string toVRML() override;

        private:
            std::vector<Type> Values;
            std::function<std::string(Type)> ToString;
            std::string Name;
        };

        template<typename Type>
        MatVariable<Type>::MatVariable(std::string name, std::function<std::string(Type)> toString, size_t numberOfComponents) {
            ToString = toString;
            Values = std::vector<Type>(numberOfComponents);
            Name = name;
        }

        template<typename Type>
        void MatVariable<Type>::setValue(size_t index, Type value) {
            Values[index] = value;
        }

        template<typename Type>
        std::string MatVariable<Type>::toVRML() {
            std::string returnValue = Name + "\t";

            for(size_t i = 0; i<Values.size(); i++)
            {
                returnValue += ToString(Values[i]);

                if(i<Values.size()-1)
                    returnValue += " ";
            }

            return returnValue;
        }

        template<typename Type>
        ComponentType MatVariable<Type>::componentType() {
            return VARIABLE;
        }

        template<typename Type>
        MatVariable<Type>::MatVariable(MatVariable<Type> &other) {
            ToString = other.ToString;
            Values = other.Values;
            Name = other.Name;
        }

        template<typename Type>
        MatVariable<Type> &MatVariable<Type>::operator=(MatVariable<Type> &other) {
            return *(new MatVariable(other));
        }
    }
}

#endif //MODERNVRML_VECTOR_H
