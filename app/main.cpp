#include <iostream>
#include <memory>
#include <string>

#include "CommandParser.h"
#include "Command.h"
#include "BasicCommands.h"
#include "FileCommands.h"
#include "FindCommands.h"

namespace tfm {

    std::unique_ptr<Command> createCommand(const std::string& name) {
        if (name == "help") {
            return std::make_unique<HelpCommand>();
        }
        if (name == "pwd") {
            return std::make_unique<PwdCommand>();
        }
        if (name == "cd") {
            return std::make_unique<CdCommand>();
        }
        if (name == "ls") {
            return std::make_unique<LsCommand>();
        }
        if (name == "mkdir") {
            return std::make_unique<MkdirCommand>();
        }
        if (name == "touch") {
            return std::make_unique<TouchCommand>();
        }
        if (name == "cat") {
            return std::make_unique<CatCommand>();
        }
        if (name == "write") {
            return std::make_unique<WriteCommand>();
        }
        if (name == "find-name") {
            return std::make_unique<FindNameCommand>();
        }
        if (name == "find-path") {
            return std::make_unique<FindPathCommand>();
        }

        return nullptr;
    }

}