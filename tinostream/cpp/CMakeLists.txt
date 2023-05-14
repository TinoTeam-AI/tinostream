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

cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
project(tinostream)

# Установка директории с исходными файлами
set(SOURCES
  cpp_api.cc
)

# Компиляция с помощью g++
add_library(tinostream SHARED ${SOURCES})

# Директории для поиска заголовочных файлов
target_include_directories(tinostream PRIVATE ../../)

# Настройки компилятора
target_compile_options(tinostream PRIVATE -Wall -fPIC)

# Связывание с библиотекой ld
target_link_libraries(tinostream dl)