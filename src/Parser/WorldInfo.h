//
// Created by moritzh on 21.07.20.
//

#ifndef MODERNVRML_WORLDINFO_H
#define MODERNVRML_WORLDINFO_H

#include "IComponent.h"

namespace ModernVRML {
    namespace Parser {
        class WorldInfo : public IComponent{
        public:
            WorldInfo() = default;
            WorldInfo(std::string info, std::string title);

            ~WorldInfo() = default;

            void setInfo(std::string info);
            void setTitle(std::string title);

            std::string toVRML() override;

            ComponentType componentType() override;
        private:
            const std::string WorldInfoTag = "WorldInfo";
            const std::string WorldInfoInfoTag = "info";
            const std::string WorldInfoTitleTag = "title";
            std::string Info = "";
            std::string Title  = "";
        };
    }
}

#endif //MODERNVRML_WORLDINFO_H
