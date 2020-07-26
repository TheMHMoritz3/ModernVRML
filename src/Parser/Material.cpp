
#include "Material.h"

ModernVRML::Parser::Material::Material(std::string name) {
    Name = name;
}

std::string ModernVRML::Parser::Material::toVRML() {
    std::string returnValue = "material " + Name + " {\n";

    for(const auto& var : Variables)
        returnValue+=var->toVRML() + "\n";

    returnValue += "}";

    return returnValue;
}

ModernVRML::Parser::ComponentType ModernVRML::Parser::Material::componentType() {
    return ModernVRML::Parser::MATERIAL;
}

void ModernVRML::Parser::Material::addVariable(std::shared_ptr<IComponent> variable) {
    Variables.push_back(variable);
}
