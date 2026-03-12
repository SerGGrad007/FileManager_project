#include <CommandParser.h>

#include <cctype>

namespace tfm {

    std::vector<std::string> CommandParser::tokenize(const std::string& input) {
        std::vector<std::string> tokens;
        std::string current;
        bool inQuotes = false;

        for (char ch : input) {
            if (ch == '"') {
                inQuotes = !inQuotes;
                continue;
            }

            if (std::isspace(static_cast<unsigned char>(ch)) && !inQuotes) {
                if (!current.empty()) {
                    tokens.push_back(current);
                    current.clear();
                }
            } else {
                current += ch;
            }
        }

        if (!current.empty()) {
            tokens.push_back(current);
        }

        return tokens;
    }

    std::optional<ParsedCommand> CommandParser::parse(const std::string& input) {
        auto tokens = tokenize(input);

        if (tokens.empty()) {
            return std::nullopt;
        }

        ParsedCommand command;
        command.name = tokens[0];

        for (std::size_t i = 1; i < tokens.size(); ++i) {
            command.args.push_back(tokens[i]);
        }

        return command;
    }

}