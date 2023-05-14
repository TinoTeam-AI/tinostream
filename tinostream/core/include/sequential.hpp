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
#include <vector>

#include "neuron.hpp"
#include "tensor.hpp"

namespace ts {
    class linear {
        private:
            vector <double> tensor();
            size_t num_neuron, num_layer;
        public:
            linear(size_t num_neuron, size_t num_layer);
            linear(size_t num_neuron);

            void work(activation active);
    };

    class sequential {
        private:

        public:
            // input_layer, hidden_layer, out
            sequential(linear input_layer, linear hidden_layer, linear output_layer, activation active);
    };
}