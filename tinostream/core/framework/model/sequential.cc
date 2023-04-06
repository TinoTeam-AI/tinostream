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

tinostream::model::sequential::sequential(linear input_layer, linear hidden_layer, linear output_layer, tinostream::activation active) {
    this->active = active;
    this->input_layer = input_layer;
    this->hidden_layer = hidden_layer;
    this->output_layer = output_layer;
}

void tinostream::model::sequential::operator()(std::vector <double> inputs) {
    input_layer.setActivation(active);
    input_layer.setWeights(weights[0]);
    output = input_layer(inputs);

    size_t numLayer = 1;
    for (; numLayer <= hidden_layer.GetQlayer(); numLayer++) {
        inputs = output;
        output.clear();
        
        hidden_layer.setActivation(active);
        hidden_layer.setWeights(weights[numLayer]);
        output = hidden_layer(inputs);
    }
    
    inputs = output;
    output.clear();

    output_layer.setActivation(active);
    output_layer.setWeights(weights[numLayer]);

    output = output_layer(inputs);
}