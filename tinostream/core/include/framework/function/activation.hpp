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
#include <vector>  
#include <cmath>

#ifdef __cplusplus
extern "C++" {
#endif

namespace tinostream {

    enum activation {
        RELU,
        SIGMOID,
        SOFTMAX
    }; 

    // f(x) = 1 / 1 + e^-x
    double sigmoid(double input);

    // f(x) = max(0, x)
    double ReLU(double input);

    // S(y) = e^y / E (e^y)
    std::vector <double> softmax(std::vector <double> vec);
}

#ifdef __cplusplus
}
#endif