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


#ifdef __cplusplus
extern "C++" {
#endif

namespace tinostream {
    template <typename T>
    class rank;

    template <typename T>
    class value : rank;
    template <typename T>
    class vector : rank;
    template <typename T>
    class matrix : rank;
    template <typename T>
    class tensor : rank;


    /* container */
    template <typename T, rank R>
    class space {
        public:
            
    };
}

#ifdef __cplusplus
}
#endif