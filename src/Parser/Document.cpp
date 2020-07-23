//
// Created by moritzh on 21.07.20.
//

#include "Document.h"
#include <filesystem>
#include <fstream>

ModernVRML::Parser::Document::Document(std::string file) {
    FilePath = file;
}

void ModernVRML::Parser::Document::addComponent(std::shared_ptr<IComponent> component) {
    Components.push_back(component);
}

void ModernVRML::Parser::Document::writeFile() {
    std::filesystem::path path{FilePath};
    std::filesystem::create_directories(path.parent_path());

    std::string writtenValue = VersionComment+"\n";
    for(const auto& component : Components)
    {
        writtenValue+=component->toVRML()+"\n";
    }

    std::ofstream ofs(path);
    ofs<<writtenValue;
    ofs.flush();
    ofs.close();
}
