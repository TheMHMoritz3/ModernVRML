//
// Created by moritzh on 21.07.20.
//

#ifndef MODERNVRML_DOCUMENT_H
#define MODERNVRML_DOCUMENT_H

#include <string>
#include <memory>
#include <vector>
#include "IComponent.h"

namespace ModernVRML {
    namespace Parser {
        class Document {
        public:
            Document() = delete;
            Document(std::string file);

            void addComponent(std::shared_ptr<IComponent> component);

            void writeFile();
        private:
            std::vector<std::shared_ptr<IComponent>> Components;
            std::string FilePath;
            const std::string VersionComment = "#VRML V2.0 utf8";
        };
    }
}

#endif //MODERNVRML_DOCUMENT_H
