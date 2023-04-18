# ===============================================================
# TinoStream - open-source machine learning framework
# Copyright (C) 2023 The TinoStream authors
#
# Licensed under the Apache License v.2;
# You may not use this file except in compliance with the License
# 
# https://github.com/TinoTeam-AI/tinostream/blob/main/license
# 
# All Rights Reserved
# ===============================================================

cmake_minimum_required(VERSION 3.18)
project(tinostream)

set(CMAKE_CXX_STANDARD 17)

add_library(tinostream SHARED cpp_api.cc)
target_include_directories(tinostream PRIVATE tinostream/core tinostream/cpp)

target_link_libraries(tinostream dl)