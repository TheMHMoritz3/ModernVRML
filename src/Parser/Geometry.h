#ifndef MODERNVRML_GEOMETRY_H
#define MODERNVRML_GEOMETRY_H

#include "IComponent.h"
#include "parser_global.h"
#include <memory>
#include <vector>

namespace ModernVRML {
    namespace Parser {
        class PARSER_EXPORT Geometry : public IComponent {
        public:
            Geometry()=default;
            Geometry(std::string name);
            virtual ~Geometry() = default;

            ComponentType componentType() override;
            std::string toVRML() override;

            void addComponent(std::shared_ptr<IComponent> component);

        private:
            const std::string GeometryTag = "geometry";
            std::string Name;
            std::vector<std::shared_ptr<IComponent>> Components;
        };
    }
}

#endif //MODERNVRML_GEOMETRY_H
