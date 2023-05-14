/* =============================================================== 
// TinoStream - open-source machine learning framework
// Copyright (C) 2023 The TinoStream authors
//
// Licensed under the Apache License v.2;
// You may not use this file except in compliance with the License
// 
// https://github.com/TinoTeam-AI/tinostream/blob/main/license
// 
// All Rights Reserved
=============================================================== */

#pragma once
#include "tinostream/core/util/data/json/JsonTools.cc"

namespace ts {

std::vector <std::string> GetJsonArray(const std::string path, const std::string arrayName) {
    CheckJSON(path, arrayName);
    std::vector <std::string> values = readJSON(path, arrayName);
    return values;
}

void SetJsonArrayStr(const std::string path, const std::string arrayName, std::vector <std::string> input) {
    CheckJSON(path, arrayName);
    writeJSON(path, input, arrayName);
}

void SetJsonArray(const std::string path, const std::string arrayName, std::vector <double> input) {
    CheckJSON(path, arrayName);
    writeJSON(path, DoubleToString(input), arrayName);
}

void SetJsonArrayDelStr(const std::string path, const std::string arrayName, std::vector <std::string> input) {
    CheckJSON(path, arrayName);
    writeJSONdel(path, input, arrayName);
}

void SetJsonArrayDel(const std::string path, const std::string arrayName, std::vector <double> input) {
    CheckJSON(path, arrayName);
    writeJSONdel(path, DoubleToString(input), arrayName);
}

} // namespace ts