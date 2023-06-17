#ifndef VOCABER_GET_JSON_FROM_FILE_H
#define VOCABER_GET_JSON_FROM_FILE_H

#include <string>
#include <fstream>
#include "../../include/nlohmann/json.hpp"

namespace vocaber_utilities {
    /**
     * @param filename - file path
     * @returns nlohmann::json from provided file or empty string on error
     */
    nlohmann::json get_json_from_file(const std::string &filename);
}

#endif //VOCABER_GET_JSON_FROM_FILE_H
