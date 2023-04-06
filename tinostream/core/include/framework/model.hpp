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

#ifdef __cplusplus
extern "C++" {
#endif

namespace tinostream {

    namespace model {

        /* The linear structure is an implementation of linear layers of neural networks

        It has a number of public methods:
            Such as constructors that take as input parameters the number of layers and neurons in them.
            Getters and Setters of Struct Fields.
            As well as the main functor for its operation, which takes as a parameter an input vector and an overloaded assignment operator.

        In the private fields of the class, it has a variable number of layers and neurons in them, 
        the layer activation function and the weight matrix */
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

        /* The sequential structure is used to implement sequential neural networks of various architectures.

            It contains a number of public methods for its operation:
                66 | sequential() - the main class constructor that accepts objects of classes of neural network architectures.
                67 | The main functor for implementing the operation of a neural network that takes an input vector as input parameters.
                Output Getters and Weight Setters. 

            It also contains private class fields for its work. Such as layers objects, output vector, and weights tensor 
        */  
        struct sequential {
            sequential(linear input_layer, linear hidden_layer, linear output_layer, activation active);
            void operator()(std::vector <double> inputs);

            std::vector <double> GetOutput();
            void setWeight(tensor <double> weights);
            
            private:
                linear input_layer, hidden_layer, output_layer;
                std::vector <double> output;
                tensor <double> weights;
                activation active;
        };
    }
} // namespace tinostream 

#ifdef __cplusplus
}
#endif