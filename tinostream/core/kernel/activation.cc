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
#include <vector>
#include <cmath>

namespace ts {

enum activation {
    RELU,
    SIGMOID,
    SOFTMAX
};

double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

double relu(double input) {
    if (input > 0) return input;
    else return 0;
}

std::vector <double> softmax(std::vector <double> vec) {
    double sum = 0;
    std::vector <double> result(vec.size());
    for (double val : vec) sum += exp(val);
    for (int i = 0; i < vec.size(); i++) result[i] = exp(vec[i]) / sum;
    return result;
}

} // namespace ts