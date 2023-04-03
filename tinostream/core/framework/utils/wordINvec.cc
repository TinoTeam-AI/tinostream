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
#include "tinostream/core/include/utils/wordINvec.hpp"

std::vector <double> OneHot(std::vector <std::string> dictionary, std::string sentence) {
    std::vector <double> one_hot_vector(dictionary.size(), 0);
    std::stringstream ss(sentence);
    std::string word;
    
    while (ss >> word) {
        for (int i = 0; i < dictionary.size(); i++) {
            if (word == dictionary[i]) {
                one_hot_vector[i] = 1;
                break;
            }
        }
    }
    
    return one_hot_vector;
}

void ChekDictionary(const std::vector <std::string>& dictionary, const std::string& sentence) {
    
}

std::vector <double> wordINvec(std::vector <std::string> dictionary, std::string sentence, std::string word) {
    std::vector <double> input;

    // Checking if all the words from the sentence are in the dictionary
    ChekDictionary(dictionary, sentence);

    // Calculate the context vector
    std::vector <double> context;
    std::vector <double> oneHot_one = OneHot(dictionary, sentence);
    AutoEncoder nn_one(oneHot_one.size(), 10);
    context = nn_one.work(oneHot_one);

    // Calculate the embeding vector
    std::vector <double> embeding;
    std::vector <double> oneHot_two = OneHot(dictionary, word);
    AutoEncoder nn_two(oneHot_two.size(), 10);
    embeding = nn_two.work(oneHot_two);

    // Smoothing a value with a sigmoid
    for (size_t i = 0; i < context.size(); i++) {
        input.at(i) = sigmoid(context.at(i) * embeding.at(i));
    }
    
    return input;
}