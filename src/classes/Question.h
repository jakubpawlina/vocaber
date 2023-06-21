#ifndef VOCABER_QUESTION_H
#define VOCABER_QUESTION_H

#include <string>
#include <utility>
#include <vector>
#include "../../include/nlohmann/json.hpp"
#include "../utilities/validate_json_input.h"


class Question {
private:
    std::string term_;
    std::string definition_;
    std::string imagePath_;

public:
    Question(std::string term, std::string definition, std::string imagePath) :
        term_(std::move(term)), definition_(std::move(definition)), imagePath_(std::move(imagePath)) {}

    [[maybe_unused]] std::string getTerm() {
        return std::string{term_};
    }

    [[maybe_unused]] std::string getDefinition() {
        return std::string{definition_};
    }

    [[maybe_unused]] std::string getImagePath() {
        return std::string{imagePath_};
    }
};

#endif //VOCABER_QUESTION_H
