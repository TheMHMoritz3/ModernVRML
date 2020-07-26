#ifndef MODERNVRML_ICOMPONENT_H
#define MODERNVRML_ICOMPONENT_H

#include "parser_global.h"
#include <string>

namespace ModernVRML {
    namespace Parser {
        enum ComponentType {
            WORLD_INFO,
            SHAPE,
            MATERIAL,
            GEOMETRY,
            COORDINATE,
            APPEARANCE,
            VECTOR,
            VARIABLE
        };

        class PARSER_EXPORT IComponent {
        public:
            virtual ~IComponent() = default;

            virtual ComponentType componentType()=0;

            virtual std::string toVRML() = 0;

        protected:
            const std::string DEFTag = "DEF";
        };
    }
}

#endif //MODERNVRML_ICOMPONENT_H
