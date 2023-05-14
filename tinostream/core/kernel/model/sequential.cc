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
#include "tinostream/cpp/include/sequential.hpp"

namespace ts {

    linear::linear(size_t num_neuron, size_t num_layer) {
        this->num_neuron = num_neuron;
        this->num_layer = num_layer;
    }

    linear::linear(size_t num_neuron) {
        this->num_neuron = num_neuron;
        this->num_layer = 1;
    }

    void linear::work(activation active) {

    }

}