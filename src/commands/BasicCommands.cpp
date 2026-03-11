#include "BasicCommands.h"
#include "FileSystemService.h"

#include <filesystem>
#include <iostream>

namespace tfm {

bool HelpCommand::execute(const std::vector<std::string>& args) {
    if (!args.empty()) {
        std::cerr << "Usage: " << getUsage() << '\n';
        return false;
    }

    std::cout << "Available commands:\n";
    std::cout << "  help  - show available commands\n";
    std::cout << "  pwd   - print current directory\n";
    std::cout << "  cd    - change directory\n";
    std::cout << "  ls    - list directory contents\n";
    std::cout << "  mkdir - create directory\n";
    std::cout << "  touch - create file\n";
    std::cout << "  exit  - quit program\n";

    return true;
}

std::string HelpCommand::getName() const {
    return "help";
}

std::string HelpCommand::getDescription() const {
    return "Show available commands";
}

std::string HelpCommand::getUsage() const {
    return "help";
}

std::string PwdCommand::getName() const {
    return "pwd";
}

std::string PwdCommand::getDescription() const {
    return "Print current directory";
}

std::string PwdCommand::getUsage() const {
    return "pwd";
}

std::string CdCommand::getName() const {
    return "cd";
}

std::string CdCommand::getDescription() const {
    return "Change current directory";
}

std::string CdCommand::getUsage() const {
    return "cd <path>";
}



std::string LsCommand::getName() const {
    return "ls";
}

std::string LsCommand::getDescription() const {
    return "List directory contents";
}

std::string LsCommand::getUsage() const {
    return "ls [path]";
}

} // namespace tfm
