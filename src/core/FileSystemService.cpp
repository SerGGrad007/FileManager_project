#include <FileSystemService.h>

namespace tfm {

namespace fs = std::filesystem;

    fs::path FileSystemService::makeAbsolute(const fs::path& path) {
        if (path.is_absolute()) {
            return path;
        }
        return fs::current_path() / path;
    }

    fs::path FileSystemService::getCurrentPath() {
        try {
            return fs::current_path();
        } catch (...) {
            return {};
        }
    }

    bool FileSystemService::exists(const fs::path& path) {
        try {
            return fs::exists(makeAbsolute(path));
        } catch (...) {
            return false;
        }
    }

    bool FileSystemService::isDirectory(const fs::path& path) {
        try {
            return fs::is_directory(makeAbsolute(path));
        } catch (...) {
            return false;
        }
    }

    std::optional<std::string> FileSystemService::changeDirectory(const fs::path& path) {
        try {
            if (path.empty()) {
                return "Path is empty";
            }

            fs::path target = makeAbsolute(path);

            if (!fs::exists(target)) {
                return "Directory does not exist";
            }

            if (!fs::is_directory(target)) {
                return "Path is not a directory";
            }

            fs::current_path(target);
            return std::nullopt;
        } catch (const fs::filesystem_error& e) {
            return e.what();
        } catch (const std::exception& e) {
            return e.what();
        }
    }

    std::optional<std::vector<fs::directory_entry>> FileSystemService::listDirectory(const fs::path& path) {
        try {
            fs::path target = makeAbsolute(path);

            if (!fs::exists(target) || !fs::is_directory(target)) {
                return std::nullopt;
            }

            std::vector<fs::directory_entry> entries;
            for (const auto& entry : fs::directory_iterator(target)) {
                entries.push_back(entry);
            }

            return entries;
        } catch (...) {
            return std::nullopt;
        }
    }

    std::optional<std::string> FileSystemService::createDirectory(const fs::path& path) {
        try {
            if (path.empty()) {
                return "Path is empty";
            }

            fs::path target = makeAbsolute(path);

            if (fs::exists(target)) {
                return "Path already exists";
            }

            fs::create_directories(target);
            return std::nullopt;
        } catch (const fs::filesystem_error& e) {
            return e.what();
        } catch (const std::exception& e) {
            return e.what();
        }
    }

}
