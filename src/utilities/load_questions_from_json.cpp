#include "load_questions_from_json.h"

std::vector<Question> loadFromJSON(const nlohmann::json &json) {
    if (vocaber_utilities::validate_json_input(json)) {
        std::vector <Question> result;
        std::vector <nlohmann::json> entries = json.at("entries");
        for (const auto &entry : entries) {
            result.emplace_back(entry.at("term"), entry.at("definition"), entry.at("image"));
        }
        return result;
    } else {
        return {};
    }
}
