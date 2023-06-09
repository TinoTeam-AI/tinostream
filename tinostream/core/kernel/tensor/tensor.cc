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
#include "tinostream/cpp/include/tensor.hpp"

namespace ts {
    
    template<typename T> tensor<T>::tensor() {
        size = 0;
        data_ = new T[size];
    }

    template<typename T> tensor<T>::~tensor() {
        delete[] data_;
    }

    template<typename T> void tensor<T>::pushBack(const T& value) {
        data_[size++] = value;
    }

    template<typename T> T& tensor<T>::operator[](size_t index) {
        return data_[index];
    }

}