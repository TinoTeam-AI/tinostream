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

namespace ts {
    enum activation {
        RELU,
        SIGMOID
    };

    class neuron {
        private:
            std::vector <double> input;
            std::vector <double> weights;
        public:
            
    };
}