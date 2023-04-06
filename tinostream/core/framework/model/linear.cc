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

int tinostream::model::linear::GetQlayer() { return Qlayer; }
int tinostream::model::linear::GetQneuron() { return Qneuron; }

void tinostream::model::linear::setWeights(std::vector <std::vector <double>> weights) { this->weights = weights; }
void tinostream::model::linear::setActivation(activation active) { this->active = active; }

tinostream::model::linear::linear() {};
tinostream::model::linear::linear(int Qneuron) {
    this->Qlayer = 1;
    this->Qneuron = Qneuron;
}
tinostream::model::linear::linear(int Qlayer, int Qneuron) {
    this->Qlayer = Qlayer;
    this->Qneuron = Qneuron;
};

tinostream::model::linear& tinostream::model::linear::operator = (linear &x) {
    this->Qlayer = x.Qlayer;
    this->Qneuron = x.Qneuron;
    return *this;
}

std::vector <double> tinostream::model::linear::operator()(std::vector <double> inputs) {
    // Написать потом вызов придупреждения, если входные данные не будут равняться количесвту нейронов 
    std::vector <double> output;
    for (size_t i = 0; i < Qlayer; i++) {
        for (size_t j = 0; j < Qneuron; j++) {
            output[i] = neuron(weights[i], inputs, active);
        }
    }
    return output;
}