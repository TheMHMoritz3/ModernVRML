//
// Created by moritzh on 21.07.20.
//

#ifndef MODERNVRML_MATERIAL_H
#define MODERNVRML_MATERIAL_H

#include "IComponent.h"
#include <memory>
#include "Variable.h"

namespace ModernVRML {
    namespace Parser {
        class Material : public IComponent{
        public:
            Material()=delete;
            Material(std::string name);

            std::string toVRML() override;
            ComponentType componentType() override;

            void addVariable(std::shared_ptr<IComponent> variable);

        private:
            std::vector<std::shared_ptr<IComponent>> Variables;
            std::string Name;
        };
    }
}
#endif //MODERNVRML_MATERIAL_H
