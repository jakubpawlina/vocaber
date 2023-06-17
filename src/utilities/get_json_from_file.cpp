#include "get_json_from_file.h"

nlohmann::json vocaber_utilities::get_json_from_file(const std::string &filename) {
    std::ifstream file(filename);
    std::string input{};
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            input += line;
            input += "\n";
        }
        file.close();
        try {
            nlohmann::json input_json = nlohmann::json::parse(input);
            return input_json;
        } catch (const std::exception& e) {
            return "";
        }
    } else {
        return "";
    }
}