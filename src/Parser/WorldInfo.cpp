//
// Created by moritzh on 21.07.20.
//

#include "WorldInfo.h"

ModernVRML::Parser::ComponentType ModernVRML::Parser::WorldInfo::componentType() {
    return ModernVRML::Parser::WORLD_INFO;
}

std::string ModernVRML::Parser::WorldInfo::toVRML() {
    std::string returnValue = WorldInfoTag + " {\n";
    returnValue += WorldInfoTitleTag + "\t\"" + Title + "\"\n";
    returnValue += WorldInfoInfoTag + "\t\"" + Info + "\"\n";
    returnValue +="}\n";
    return returnValue;
}

ModernVRML::Parser::WorldInfo::WorldInfo(std::string info, std::string title) {
    Info = info;
    Title = title;
}

void ModernVRML::Parser::WorldInfo::setInfo(std::string info) {
    Info = info;
}

void ModernVRML::Parser::WorldInfo::setTitle(std::string title) {
    Title = title;
}
