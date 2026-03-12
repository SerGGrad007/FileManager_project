#include "FindCommands.h"
#include "FileSystemService.h"
#include "PathUtils.h"
#include <filesystem>
#include <iostream>

namespace tfm {
    bool FindNameCommand::execute(const std::vector<std::string>& args) {
        if (args.size() != 1) {
            std::cerr << "Usage: " << getUsage() << '\n';
            return false;
        }

        auto results = FileSystemService::findByName(
            std::filesystem::current_path(),
            args[0]
        );

        if (results.empty()) {
            std::cout << "No files found matching: " << args[0] << '\n';
            return true;
        }

        std::cout << "Found " << results.size() << " result(s):\n";
        for (const auto& path : results) {
            std::cout << PathUtils::toString(path) << '\n';
        }

        return true;
    }
}
