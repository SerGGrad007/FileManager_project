#include <FileSystemService.h>

#include <sstream>
#include <fstream>

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

    std::optional<std::string> FileSystemService::createFile(const fs::path& path) {
        try {
            if (path.empty()) {
                return "Path is empty";
            }

            fs::path target = makeAbsolute(path);

            if (target.has_parent_path()) {
                fs::create_directories(target.parent_path());
            }

            std::ofstream file(target, std::ios::app);
            if (!file.is_open()) {
                return "Cannot create file";
            }

            return std::nullopt;
        } catch (const fs::filesystem_error& e) {
            return e.what();
        } catch (const std::exception& e) {
            return e.what();
        }
    }

    std::optional<std::string> FileSystemService::readFile(const fs::path& path) {
        try {
            fs::path target = makeAbsolute(path);

            if (!fs::exists(target)) {
                return std::nullopt;
            }

            if (fs::is_directory(target)) {
                return std::nullopt;
            }

            std::ifstream file(target);
            if (!file.is_open()) {
                return std::nullopt;
            }

            std::ostringstream buffer;
            buffer << file.rdbuf();
            return buffer.str();
        } catch (...) {
            return std::nullopt;
        }
    }

    std::optional<std::string> FileSystemService::writeFile(
        const fs::path& path,
        const std::string& content
    ) {
        try {
            if (path.empty()) {
                return "Path is empty";
            }

            fs::path target = makeAbsolute(path);

            if (target.has_parent_path()) {
                fs::create_directories(target.parent_path());
            }

            std::ofstream file(target);
            if (!file.is_open()) {
                return "Cannot open file for writing";
            }

            file << content;
            return std::nullopt;
        } catch (const fs::filesystem_error& e) {
            return e.what();
        } catch (const std::exception& e) {
            return e.what();
        }
    }

}
