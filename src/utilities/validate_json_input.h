#ifndef VOCABER_VALIDATE_JSON_INPUT_H
#define VOCABER_VALIDATE_JSON_INPUT_H

#include "../../include/nlohmann/json.hpp"

namespace vocaber_utilities {
    /**
     * @param input_json - JSON with program data
     * @returns 1 for valid input and 0 for invalid one
     */
    bool validate_json_input(nlohmann::json input_json);
}

#endif //VOCABER_VALIDATE_JSON_INPUT_H
