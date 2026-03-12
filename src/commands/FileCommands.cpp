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
}