#ifndef MODERNVRML_APPEARANCE_H
#define MODERNVRML_APPEARANCE_H

#include <memory>
#include "IComponent.h"
#include "Material.h"
#include "parser_global.h"

namespace ModernVRML {
    namespace Parser {
        class PARSER_EXPORT Appearance : public IComponent {
        public:
            Appearance()=delete;
            Appearance(std::string name);

            std::string toVRML() override;

            ComponentType componentType() override;

            void setMaterial(std::shared_ptr<Material> material);
        private:
            std::shared_ptr<Material> _Material;
            std::string Name;
        };
    }
}


#endif //MODERNVRML_APPEARANCE_H
