#ifndef FILEMANAGER_PROJECT_FILECOMMANDS_H
#define FILEMANAGER_PROJECT_FILECOMMANDS_H
#pragma once
#include "Command.h"

namespace tfm {

    class MkdirCommand : public Command {
    public:
        bool execute(const std::vector<std::string>& args) override;
        std::string getName() const override;
        std::string getDescription() const override;
        std::string getUsage() const override;
    };

    class TouchCommand : public Command {
    public:
        bool execute(const std::vector<std::string>& args) override;
        std::string getName() const override;
        std::string getDescription() const override;
        std::string getUsage() const override;
    };

    class CatCommand : public Command {
    public:
        bool execute(const std::vector<std::string>& args) override;
        std::string getName() const override;
        std::string getDescription() const override;
        std::string getUsage() const override;
    };

    class WriteCommand : public Command {
    public:
        bool execute(const std::vector<std::string>& args) override;
        std::string getName() const override;
        std::string getDescription() const override;
        std::string getUsage() const override;
    };

}

#endif //FILEMANAGER_PROJECT_FILECOMMANDS_H