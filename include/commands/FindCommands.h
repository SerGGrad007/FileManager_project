#ifndef FILEMANAGER_PROJECT_FINDCOMMANDS_H
#define FILEMANAGER_PROJECT_FINDCOMMANDS_H
#pragma once
#include "Command.h"

namespace tfm {

    class FindNameCommand : public Command {
    public:
        bool execute(const std::vector<std::string>& args) override;
        std::string getName() const override;
        std::string getDescription() const override;
        std::string getUsage() const override;
    };

    class FindPathCommand : public Command {
    public:
        bool execute(const std::vector<std::string>& args) override;
        std::string getName() const override;
        std::string getDescription() const override;
        std::string getUsage() const override;
    };

}

#endif //FILEMANAGER_PROJECT_FINDCOMMANDS_H