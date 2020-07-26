#ifndef MODERNVRML_VECTOR_H
#define MODERNVRML_VECTOR_H

#include "IComponent.h"
#include "parser_global.h"
#include <functional>
#include <vector>

namespace ModernVRML {
    namespace Parser {
        template<typename Type>
#ifdef _WIN32
        class __declspec(dllexport) MatVector : public IComponent {
#else
        class MatVector : public IComponent {
#endif
        public:
            MatVector() = delete;
            MatVector(std::string name, std::function<std::string(Type)> toString, size_t numberOfComponents, bool withComma);
            void setValue(size_t index, Type value);

            ComponentType componentType() override;

            std::string toVRML() override;

        private:
            std::vector<Type> Values;
            std::function<std::string(Type)> ToString;
            std::string Name;
            bool WithComma = true;
        };

        template<typename Type>
        MatVector<Type>::MatVector(std::string name, std::function<std::string(Type)> toString, size_t numberOfComponents, bool withComma) {
            ToString = toString;
            Values = std::vector<Type>(numberOfComponents);
            Name = name;
            WithComma = withComma;
        }

        template<typename Type>
        void MatVector<Type>::setValue(size_t index, Type value) {
            Values.at(index) = value;
        }

        template<typename Type>
        std::string MatVector<Type>::toVRML() {
            std::string returnValue = "";

            if(Name != "")
                returnValue = Name + " ";

            returnValue+="[\n";

            for(size_t i = 0; i<Values.size(); i++)
            {
                returnValue += ToString(Values[i]);

                if((WithComma)&&(i<Values.size()-1))
                    returnValue += ",";

                returnValue += "\n";
            }

            returnValue+="]";

            return returnValue;
        }

        template<typename Type>
        ComponentType MatVector<Type>::componentType() {
            return VECTOR;
        }
    }
}

#endif //MODERNVRML_VECTOR_H
