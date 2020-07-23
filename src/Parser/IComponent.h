//
// Created by moritzh on 21.07.20.
//

#ifndef MODERNVRML_ICOMPONENT_H
#define MODERNVRML_ICOMPONENT_H

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

        class IComponent {
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
