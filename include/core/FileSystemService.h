#ifndef FILEMANAGER_PROJECT_FILESYSTEMSERVICE_H
#define FILEMANAGER_PROJECT_FILESYSTEMSERVICE_H
#pragma once

#include <filesystem>
#include <optional>
#include <vector>
#include <string>

namespace tfm {

    class FileSystemService {
    public:
        static std::filesystem::path getCurrentPath();

        static bool exists(const std::filesystem::path& path);
        static bool isDirectory(const std::filesystem::path& path);

        static std::optional<std::string> changeDirectory(
            const std::filesystem::path& path
        );

        static std::optional<std::vector<std::filesystem::directory_entry>> listDirectory(
            const std::filesystem::path& path = "."
        );

        static std::optional<std::string> createDirectory(
            const std::filesystem::path& path
        );

        static std::optional<std::string> createFile(
            const std::filesystem::path& path
        );

        static std::optional<std::string> readFile(
            const std::filesystem::path& path
        );

        static std::optional<std::string> writeFile(
            const std::filesystem::path& path,
            const std::string& content
        );

        static std::vector<std::filesystem::path> findByName(
            const std::filesystem::path& root,
            const std::string& pattern
        );

    private:
        static std::filesystem::path makeAbsolute(
            const std::filesystem::path& path
        );
    };

}
#endif //FILEMANAGER_PROJECT_FILESYSTEMSERVICE_H