#ifndef MODERNVRML_SHAPE_H
#define MODERNVRML_SHAPE_H

#include "IComponent.h"
#include "Geometry.h"
#include "Appearance.h"
#include "parser_global.h"
#include <memory>

namespace ModernVRML {
    namespace Parser {
        class PARSER_EXPORT Shape : public IComponent {
        public:
            Shape() = default;
            Shape(std::string name);
            Shape(std::shared_ptr<Shape> otherShape);
            ~Shape() = default;

            ComponentType componentType() override;
            std::string toVRML() override;

            void setAppearance(std::shared_ptr<Appearance> appear);
            void setGeometry(std::shared_ptr<Geometry> geo);

        private:
            const std::string ShapeTag = "Shape";
            std::string Name = "";
            bool UseShape = false;
            std::shared_ptr<Shape> ShapeToUse;
            std::shared_ptr<Appearance> AppearancePtr;
            std::shared_ptr<Geometry> GeometryPtr;

        };
    }
}

#endif //MODERNVRML_SHAPE_H
