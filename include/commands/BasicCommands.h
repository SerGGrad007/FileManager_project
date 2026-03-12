#ifndef FILEMANAGER_PROJECT_BASICCOMMANDS_H
#define FILEMANAGER_PROJECT_BASICCOMMANDS_H
#pragma once

#include <string>
#include <vector>
#include "Command.h"

namespace tfm {

    class HelpCommand : public Command {
    public:
        bool execute(const std::vector<std::string>& args) override;
        std::string getName() const override;
        std::string getDescription() const override;
        std::string getUsage() const override;
    };

    class PwdCommand : public Command {
    public:
        bool execute(const std::vector<std::string>& args) override;
        std::string getName() const override;
        std::string getDescription() const override;
        std::string getUsage() const override;
    };

    class CdCommand : public Command {
    public:
        bool execute(const std::vector<std::string>& args) override;
        std::string getName() const override;
        std::string getDescription() const override;
        std::string getUsage() const override;
    };

    class LsCommand : public Command {
    public:
        bool execute(const std::vector<std::string>& args) override;
        std::string getName() const override;
        std::string getDescription() const override;
        std::string getUsage() const override;
    };


}


#endif //FILEMANAGER_PROJECT_BASICCOMMANDS_H