/* ///////////////////////////////////////////////////////////////
* TinoStream - open-source machine learning framework
* Copyright (C) 2023 The TinoStream authors
*
* Licensed under the Apache License v.2;
* You may not use this file except in compliance with the License
* 
* https://github.com/VaisonE/torchstream/blob/main/license
* 
* All Rights Reserved
/////////////////////////////////////////////////////////////// */

#pragma once 
#include "tinostream/core/include/framework/function/neuron.hpp"

double tinostream::sum(std::vector <double> weight, std::vector <double> input) {  
    double sum = 0;
    for (size_t i = 0; i < weight.size(); i++) {
        sum += weight[i] * input[i];
    }
    return sum;
}

double tinostream::neuron(std::vector <double> weight, std::vector <double> input, activation activ) {
    if (activ == activation::RELU) return ReLU(sum(weight, input));
    if (activ == activation::SIGMOID) return sigmoid(sum(weight, input));
}