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

#ifdef __cplusplus
extern "C++" {
#endif

namespace tinostream {
    
    typedef std::vector <std::vector <std::vector <double>>> tensor;

}

#ifdef __cplusplus
}
#endif