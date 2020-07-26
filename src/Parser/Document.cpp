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
#ifdef _MSC_VER
    std::filesystem::path path{ FilePath };
    std::filesystem::create_directories(path.parent_path());
#else
#if(defined(__GNUC__) and (7 > __GNUC_MAJOR__))
    std::filesystem::path path{ FilePath };
    std::filesystem::create_directories(path.parent_path());
#else
    std::experimental::filesystem::path path{ FilePath };
    std::experimental::filesystem::create_directories(path.parent_path());
#endif
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
