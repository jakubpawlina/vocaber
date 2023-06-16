#include "validate_json_input.h"

bool vocaber_utilities::validate_json_input(nlohmann::json input_json) {
     try {
         input_json.at("name");
         input_json.at("entries");
     } catch (const std::exception& e) {
         return false;
     }
    return true;
}
