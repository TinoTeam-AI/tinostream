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

#ifdef __cplusplus
extern "C++" {
#endif

namespace tinostream {
    enum rank {
        vector, 
        matrix,
        tensor,
        four_tensor
    };

    template <typename T>
    class tensor {
        private:
            T* arr_;
            rank rank;
            
            struct vector;
            struct matrix;
            struct tensor;
            struct four_tensor;

        public:
            tensor(tinostream::rank);
            ~tensor();

            
    };

}

#ifdef __cplusplus
}
#endif