/* ///////////////////////////////////////////////////////////////
* TinoStream - open-source machine learning framework
* Copyright (C) 2023 The TinoStream authors
*
* Licensed under the Apache License v.2;
* You may not use this file except in compliance with the License
* 
* https://github.com/TinoTeam-AI/tinostream/blob/main/license
* 
* All Rights Reserved
/////////////////////////////////////////////////////////////// */

#pragma once
#include "tinostream/core/include/utils/json/jsonParse.hpp"

std::vector <std::string> JsonParse(const std::string path, const std::string arrayName) {
    CheckJSON(path, arrayName);
    std::vector <std::string> values = readJSON(path, arrayName);
    return values;
}

void JsonParse(const std::string path, const std::string arrayName, std::vector <std::string> input) {
    CheckJSON(path, arrayName);
    writeJSON(path, input, arrayName);
}

void JsonParse(const std::string path, const std::string arrayName, std::vector <double> input) {
    CheckJSON(path, arrayName);
    writeJSON(path, DoubleToString(input), arrayName);
}

void JsonParse(const std::string path, const std::string arrayName, std::vector <std::string> input, std::string str) {
    if (str == "del") {
        CheckJSON(path, arrayName);
        writeJSONdel(path, input, arrayName);
    } 
}

void JsonParse(const std::string path, const std::string arrayName, std::vector <double> input, std::string str) {
    if (str == "del") {
        CheckJSON(path, arrayName);
        writeJSONdel(path, DoubleToString(input), arrayName);
    }
}