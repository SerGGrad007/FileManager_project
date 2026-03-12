#include "FileCommands.h"
#include "FileSystemService.h"
#include <iostream>
#include <string>

namespace tfm {
    bool MkdirCommand::execute(const std::vector<std::string>& args) {
        if (args.size() != 1) {
            std::cerr << "Usage: " << getUsage() << '\n';
            return false;
        }

        auto error = FileSystemService::createDirectory(args[0]);
        if (error.has_value()) {
            std::cerr << "Error: " << error.value() << '\n';
            return false;
        }

        std::cout << "Directory created successfully\n";
        return true;
    }
    std::string MkdirCommand::getName() const {
        return "mkdir";
    }
    std::string MkdirCommand::getDescription() const {
        return "Create a new directory";
    }
    std::string MkdirCommand::getUsage() const {
        return "mkdir <directory_name>";
    }
    bool TouchCommand::execute(const std::vector<std::string>& args) {
        if (args.size()!= 1) {
            std::cerr <<"Usage: " << getUsage() << '\n';
            return false;
        }
        auto error = FileSystemService::createFile(args[0]);
        if (error.has_value()) {
            std:: cerr << "Error: " << error.value() << '\n';
            return false;
        }

        std::cout << "File created successfully\n";
        return true;
    }
}