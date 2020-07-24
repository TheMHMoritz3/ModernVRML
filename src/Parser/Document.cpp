//
// Created by moritzh on 21.07.20.
//

#include "Document.h"
#include <boost/filesystem.hpp>
#include <fstream>

ModernVRML::Parser::Document::Document(std::string file) {
    FilePath = file;
}

void ModernVRML::Parser::Document::addComponent(std::shared_ptr<IComponent> component) {
    Components.push_back(component);
}

void ModernVRML::Parser::Document::writeFile() {
    boost::filesystem::path path{FilePath};
    boost::filesystem::create_directories(path.parent_path());

    std::string writtenValue = VersionComment+"\n";
    for(const auto& component : Components)
    {
        writtenValue+=component->toVRML()+"\n";
    }

    std::ofstream ofs(path.c_str());
    ofs<<writtenValue;
    ofs.flush();
    ofs.close();
}
