
#include "Shape.h"

void ModernVRML::Parser::Shape::setAppearance(std::shared_ptr<Appearance> appear) {
    AppearancePtr = appear;
}

void ModernVRML::Parser::Shape::setGeometry(std::shared_ptr<Geometry> geo) {
    GeometryPtr = geo;
    GeometryPtr = geo;
}

std::string ModernVRML::Parser::Shape::toVRML() {
    std::string returnValue = ShapeTag + " {\n";

    if(Name != "")
        returnValue = DEFTag + " " + Name + " " + returnValue;

    returnValue+=AppearancePtr->toVRML()+"\n";
    returnValue+=GeometryPtr->toVRML()+"\n";
    returnValue+="}\n";
    return returnValue;
}

ModernVRML::Parser::ComponentType ModernVRML::Parser::Shape::componentType() {
    return ModernVRML::Parser::SHAPE;
}

ModernVRML::Parser::Shape::Shape(std::shared_ptr<Shape> otherShape) {
    ShapeToUse = otherShape;
    UseShape = true;
}

ModernVRML::Parser::Shape::Shape(std::string name) {
    Name = name;
}
