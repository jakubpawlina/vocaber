#ifndef VOCABER_LOAD_QUESTIONS_FROM_JSON_H
#define VOCABER_LOAD_QUESTIONS_FROM_JSON_H

#include <string>
#include <utility>
#include <vector>
#include "../classes/Question.h"
#include "../../include/nlohmann/json.hpp"
#include "../utilities/validate_json_input.h"

std::vector<Question> loadFromJSON(const nlohmann::json &json);

#endif //VOCABER_LOAD_QUESTIONS_FROM_JSON_H
