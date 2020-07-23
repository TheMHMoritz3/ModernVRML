//
// Created by moritzh on 21.07.20.
//

#include "Appearance.h"

ModernVRML::Parser::ComponentType ModernVRML::Parser::Appearance::componentType() {
    return ModernVRML::Parser::APPEARANCE;
}

std::string ModernVRML::Parser::Appearance::toVRML() {
    std::string returnValue = "appearance " + Name + " {\n";
    returnValue+= _Material->toVRML() + "\n}";
    return returnValue;
}

ModernVRML::Parser::Appearance::Appearance(std::string name) {
    Name = name;
}

void ModernVRML::Parser::Appearance::setMaterial(std::shared_ptr<ModernVRML::Parser::Material> material) {
    _Material = material;
}
