#ifndef MODERNVRML_COORDINATE_H
#define MODERNVRML_COORDINATE_H

#include "IComponent.h"
#include "parser_global.h"
#include <memory>
#include <string>
#include <vector>

namespace ModernVRML {
    namespace Parser {
        class PARSER_EXPORT Coordinate : public IComponent {
        public:
            Coordinate() = default;
            Coordinate(std::string name);
            virtual ~Coordinate() = default;

            std::string toVRML() override;
            ComponentType componentType() override;

            void addVector(std::shared_ptr<IComponent> vector);

        private:
            std::vector<std::shared_ptr<IComponent>> Vectors;
            const std::string CoordinateTag = "coord";
            std::string Name;
        };
    }
}

#endif //MODERNVRML_COORDINATE_H
