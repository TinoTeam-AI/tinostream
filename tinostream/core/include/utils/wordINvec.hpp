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
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <vector>

#ifdef __cplusplus
extern "C++" {
#endif

namespace tinostream {
    std::vector <double> OneHot(std::vector <std::string> dictionary, std::string sentence);

    void ChekDictionary(const std::vector <std::string>& dictionary, const std::string& sentence);

    std::vector <double> wordINvec(std::vector <std::string> dictionary, std::string sentence, std::string word);
}

#ifdef __cplusplus
}
#endif