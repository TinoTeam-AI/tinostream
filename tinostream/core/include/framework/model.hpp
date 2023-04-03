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
#include "function/neuron.hpp"

#include <functional>
#include <vector>

#ifdef __cplusplus
extern "C++" {
#endif

namespace tinostream {
    
    typedef std::vector <std::vector <std::vector <double>>> tensor;
    typedef std::vector <std::function<void()>> layers;

    class model {
        public:
            /*  */
            typedef std::vector <std::function<void()>> layers;
            struct sequential {
                sequential(std::vector <double> inputs);
                void work(layers layer); 
                void layer(const int Qneuron, activation active);
                
                std::vector <double> getOutput();
                    
                private: 
                    std::vector <double> input, output;
                    tensor weights;
                    int numLayer; 
            };
    };
}

#ifdef __cplusplus
}
#endif