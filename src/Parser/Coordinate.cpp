//
// Created by moritzh on 22.07.20.
//

#include "Coordinate.h"

void ModernVRML::Parser::Coordinate::addVector(std::shared_ptr<IComponent> vector) {
    Vectors.push_back(vector);
}

ModernVRML::Parser::ComponentType ModernVRML::Parser::Coordinate::componentType() {
    return ModernVRML::Parser::COORDINATE;
}

std::string ModernVRML::Parser::Coordinate::toVRML() {
    std::string returnValue = CoordinateTag +" " + Name + " {\n";
    for(const auto& value : Vectors)
    {
        returnValue += value->toVRML() + "\n";
    }
    returnValue += "}\n";
    return returnValue;
}

ModernVRML::Parser::Coordinate::Coordinate(std::string name) {
    Name = name;
}
