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
#include <string>

#ifdef __cplusplus
extern "C++" {
#endif

namespace ts {
    std::vector <std::string> GetJsonArray(const std::string, const std::string);
    
    // Написать шаблонную функцию 
    void SetJsonArray(const std::string, const std::string, std::vector <double>);
    void SetJsonArrayStr(const std::string, const std::string, std::vector <std::string>);
    // Написать шаблонную функцию 
    void SetJsonArrayDel(const std::string, const std::string, std::vector <double>);
    void SetJsonArrayDelStr(const std::string, const std::string, std::vector <std::string>);
} // namespace ts

#ifdef __cplusplus
} // end extern "C++"
#endif