#ifndef FILEMANAGER_PROJECT_COMMANDPARSER_H
#define FILEMANAGER_PROJECT_COMMANDPARSER_H
#pragma once

#include <optional>
#include <string>
#include <vector>

namespace tfm {

    struct ParsedCommand {
        std::string name;
        std::vector<std::string> args;
    };

    class CommandParser {
    public:
        static std::optional<ParsedCommand> parse(const std::string& input);

    private:
        static std::vector<std::string> tokenize(const std::string& input);
    };

}
#endif //FILEMANAGER_PROJECT_COMMANDPARSER_H