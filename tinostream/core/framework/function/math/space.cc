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

tinostream::rank {
    public:
        virtual bool isEmpty() = 0;

        virtual size_t size() = 0;
        virtual size_t capacity() = 0;

        virtual void pushBack() = 0;
        virtual void remove() = 0;
}

template <typename T>
tinostream::vector {
    private:
        T* arr_;
        size_t size;
    public:
        void pushBack(const T& value) {
            
        }
};