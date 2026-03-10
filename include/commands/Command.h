#ifndef FILEMANAGER_PROJECT_COMMAND_H
#define FILEMANAGER_PROJECT_COMMAND_H
#pragma once

#include <string>
#include <vector>

namespace tfm {

    class Command {
    public:
        virtual ~Command() = default;

        virtual bool execute(const std::vector<std::string>& args) = 0;
        virtual std::string getName() const = 0;
        virtual std::string getDescription() const = 0;
        virtual std::string getUsage() const = 0;
    };

}

#endif //FILEMANAGER_PROJECT_COMMAND_H