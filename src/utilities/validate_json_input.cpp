#include "validate_json_input.h"

bool vocaber_utilities::validate_json_input(nlohmann::json input_json) {
     try {
         input_json.at("name");
         std::vector <nlohmann::json> entries = input_json.at("entries");
         for (const auto &entry : entries) {
             entry.at("term");
             entry.at("definition");
             entry.at("image");
         }
     } catch (const std::exception& e) {
         return false;
     }
    return true;
}
