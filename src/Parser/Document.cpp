#include "Document.h"
#include <fstream>

#ifdef _WIN32
#include <filesystem>
#else
#include <boost/filesystem.hpp>
#endif

ModernVRML::Parser::Document::Document(std::string file) {
    FilePath = file;
}

void ModernVRML::Parser::Document::addComponent(std::shared_ptr<IComponent> component) {
    Components.push_back(component);
}

void ModernVRML::Parser::Document::writeFile() {
#ifdef _WIN32
    std::filesystem::path path{ FilePath };
    std::filesystem::create_directories(path.parent_path());
#else
    boost::filesystem::path path{ FilePath };
    boost::filesystem::create_directories(path.parent_path());
#endif


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
