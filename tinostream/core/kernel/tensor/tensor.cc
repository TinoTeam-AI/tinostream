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

namespace ts {

template<typename T> class tensor {
    private:
        std::vector <std::vector <std::vector <T>>> arr_;
        int rank;
        size_t size_x, size_y, size_z;
    public:
        tensor(int rank) {
            this->rank = rank;
            size_x = 1;
            size_y = 1;
            size_z = 1;

            arr_[size_x][size_y][size_z] = 1;
        }

        //T& operator [](size_t index_x) {
          //  return arr_[index_x];
        //}

        T PushBack(size_t index) {
            return arr_[size_x][size_y][size_z];
        }
};

} // namespace ts