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
#include <random>
#include <vector>
#include <string>
#include <cmath>

#ifdef __cplusplus
extern "C++" {
#endif

namespace ts {

template<typename T> class tensor {
    public:
        tensor(int);

        T& operator [](size_t);

        T PushBack(size_t);
};

} // namespace ts

#ifdef __cplusplus
} // end extern "C++"
#endif