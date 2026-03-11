#ifndef FILEMANAGER_PROJECT_PATHUTILS_H
#define FILEMANAGER_PROJECT_PATHUTILS_H

#pragma once

#include <filesystem>
#include <string>

namespace tfm {

    class PathUtils {
    public:
        static std::filesystem::path makeAbsolute(const std::filesystem::path& path);
        static std::filesystem::path getParent(const std::filesystem::path& path);
        static std::string getFilename(const std::filesystem::path& path);
        static bool isAbsolute(const std::filesystem::path& path);
        static bool isEmpty(const std::filesystem::path& path);
        static std::string toString(const std::filesystem::path& path);
    };
}
#endif //FILEMANAGER_PROJECT_PATHUTILS_H