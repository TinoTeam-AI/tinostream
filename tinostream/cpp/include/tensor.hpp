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
#include <cstddef>

#ifdef __cplusplus
extern "C++" {
#endif

namespace ts {
    template<typename T> class tensor {
        private: 
            T* data_;
            size_t size;
        public:
            tensor();
            ~tensor();

            void pushBack(const T& value);
            
            T& operator [](size_t index_x);
    };
}

#ifdef __cplusplus
} // end extern "C++"
#endif