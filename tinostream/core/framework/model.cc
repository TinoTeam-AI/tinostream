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
#include "tinostream/core/include/framework/model.hpp"

std::vector <double> tinostream::model::sequential::getOutput() { return output; }
tinostream::model::sequential::sequential(std::vector <double> input) { this->input = input; }

void tinostream::model::sequential::work(layers layer) {
    for (auto &l : layer) {
        l();
    }
}

// Loop to call a neuron function
void tinostream::model::sequential::layer(const int Qneuron, activation active) {
    for (size_t i = 0; i < Qneuron; i++) {
        output[i] = neuron(weights[numLayer][i], input, active);
    } 
}