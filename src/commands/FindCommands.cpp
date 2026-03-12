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
    std::string FindNameCommand::getName() const {
        return "find-name";
    }

    std::string FindNameCommand::getDescription() const {
        return "Find files by name";
    }

    std::string FindNameCommand::getUsage() const {
        return "find-name <pattern>";
    }

    bool FindPathCommand::execute(const std::vector<std::string>& args) {
        if (args.size() != 1) {
            std::cerr << "Usage: " << getUsage() << '\n';
            return false;
        }

        std::filesystem::path target = PathUtils::makeAbsolute(args[0]);

        if (!std::filesystem::exists(target)) {
            std::cerr << "Path not found: " << target << '\n';
            return false;
        }

        std::cout << "Found: " << target << '\n';

        if (std::filesystem::is_directory(target)) {
            std::cout << "Type: directory\n";
        } else {
            std::cout << "Type: file\n";
            std::cout << "Size: " << std::filesystem::file_size(target) << " bytes\n";
        }

        return true;
    }



}
