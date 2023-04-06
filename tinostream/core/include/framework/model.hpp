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
#include "function/math/tensor.hpp"
#include "function/neuron.hpp"

//#include <functional>

#ifdef __cplusplus
extern "C++" {
#endif

namespace tinostream {

    namespace model {

        /*  */
        struct linear {
            linear(int Qlayer, int Qneuron);
            linear(int Qneuron);
            linear();
            int GetQlayer();
            int GetQneuron();

            void setWeights(std::vector <std::vector <double>> weights);
            void setActivation(activation active);

            std::vector <double> operator()(std::vector <double> inputs);
            linear& operator = (linear &x);
            private:
                std::vector <std::vector <double>> weights;
                activation active;
                int Qlayer;
                int Qneuron;
        };

        /*  */  
        struct sequential {
            sequential(linear input_layer, linear hidden_layer, linear output_layer, activation active);
            void operator()(std::vector <double> inputs);

            private: 
                int input_size, hidden_size, output_size;
                activation active;
            private:
                linear input_layer, hidden_layer, output_layer;
                std::vector <double> output;
                tensor weights;
        };
    };
} // namespace tinostream 

#ifdef __cplusplus
}
#endif