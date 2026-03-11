#include "PathUtils.h"

namespace tfm {

    namespace fs = std::filesystem;

    fs::path PathUtils::makeAbsolute(const fs::path& path) {
        if (path.is_absolute()) {
            return path;
        }

        return fs::current_path() / path;
    }

    fs::path PathUtils::getParent(const fs::path& path) {
        return path.parent_path();
    }

    std::string PathUtils::getFilename(const fs::path& path) {
        return path.filename().string();
    }

    bool PathUtils::isAbsolute(const fs::path& path) {
        return path.is_absolute();
    }

    bool PathUtils::isEmpty(const fs::path& path) {
        return path.empty();
    }

    std::string PathUtils::toString(const fs::path& path) {
        return path.string();
    }

}