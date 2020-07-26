
#include "Geometry.h"

ModernVRML::Parser::Geometry::Geometry(std::string name) {
    Name = name;
}

void ModernVRML::Parser::Geometry::addComponent(std::shared_ptr<IComponent> component) {
    Components.push_back(component);
}

ModernVRML::Parser::ComponentType ModernVRML::Parser::Geometry::componentType() {
    return ModernVRML::Parser::GEOMETRY;
}

std::string ModernVRML::Parser::Geometry::toVRML() {
    std::string returnValue = GeometryTag + " " + Name + " {\n";
    for(const auto& component : Components)
    {
        returnValue+=component->toVRML()+"\n";
    }
    returnValue += "}\n";
    return returnValue;
}
