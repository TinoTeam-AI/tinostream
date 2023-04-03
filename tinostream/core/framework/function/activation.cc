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
#include "tinostream/core/include/framework/function/activation.hpp"

// 1 / 1 + e^-x
double tinostream::sigmoid(double input) {
    const double e = 2.7182;
    return 1 / (1 + pow(e, -input));  
}

// f(x) = max(0, x)
double tinostream::ReLU(double input) {
    if (input > 0) return input;
    else return 0;
}

// S(y) = e^y / E (e^y)
std::vector <double> tinostream::softmax(std::vector <double> vec) {
    double sum = 0;
    std::vector <double> result(vec.size());
    for (double val : vec) sum += exp(val);
    for (int i = 0; i < vec.size(); i++) result[i] = exp(vec[i]) / sum;
    return result;
}