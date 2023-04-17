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
#include "rapidjson/stringbuffer.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

using namespace rapidjson;

// Function to read values from a JSON array
std::vector <std::string> readJSON(std::string path, std::string arrayName) {
    std::vector<std::string> values;

    std::ifstream file(path);
    if (file.is_open()) {
        std::string jsonString((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

        Document document;
        document.Parse(jsonString.c_str());

        if (document.HasMember(arrayName.c_str()) && document[arrayName.c_str()].IsArray()) {
            const Value& array = document[arrayName.c_str()];
            for (SizeType i = 0; i < array.Size(); i++) {
                values.push_back(array[i].GetString());
            }
        }
    }
    return values;
}

// Function to write values to json array
void writeJSON(std::string path, std::vector <std::string> input, std::string arrayName) {
    std::ifstream file(path);
    if (file.is_open()) {
        std::string jsonString((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

        Document document;
        document.Parse(jsonString.c_str());

        if (document.HasMember(arrayName.c_str()) && document[arrayName.c_str()].IsArray()) {
            Value& array = document[arrayName.c_str()];
            for (int i = 0; i < input.size(); i++) {
                Value value(input[i].c_str(), document.GetAllocator());
                array.PushBack(value, document.GetAllocator());
            }
        } else {
            Value array(kArrayType);
            for (int i = 0; i < input.size(); i++) {
                Value value(input[i].c_str(), document.GetAllocator());
                array.PushBack(value, document.GetAllocator());
            }
            document.AddMember(StringRef(arrayName.c_str()), array, document.GetAllocator());
        }

        StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        document.Accept(writer);

        std::ofstream outfile(path);
        outfile << buffer.GetString();
        outfile.close();
    }
}

// A function for writing values to a json array, while all its contents are erased
void writeJSONdel(std::string path, std::vector<std::string> input, std::string arrayName) {
    std::ifstream file(path);
    if (file.is_open()) {
        std::string jsonString((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

        Document document;
        document.Parse(jsonString.c_str());

        if (document.HasMember(arrayName.c_str()) && document[arrayName.c_str()].IsArray()) {
            document[arrayName.c_str()].Clear();
            for (int i = 0; i < input.size(); i++) {
                Value value(input[i].c_str(), document.GetAllocator());
                document[arrayName.c_str()].PushBack(value, document.GetAllocator());
            }
        } else {
            Value array(kArrayType);
            for (int i = 0; i < input.size(); i++) {
                Value value(input[i].c_str(), document.GetAllocator());
                array.PushBack(value, document.GetAllocator());
            }
            document.AddMember(StringRef(arrayName.c_str()), array, document.GetAllocator());
        }

        StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        document.Accept(writer);

        std::ofstream outfile(path);
        outfile << buffer.GetString();
        outfile.close();
    }
}

// Function to create a new JSON file or add an array to an existing JSON file
void CheckJSON(std::string path, std::string arrayName) {
    std::ifstream file(path);
    if (file.is_open()) {
        std::string jsonString((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

        Document document;
        document.Parse(jsonString.c_str());
        if (!document.IsObject()) document.SetObject();

        if (document.HasMember(arrayName.c_str()) && document[arrayName.c_str()].IsArray()) {
            std::cerr << "Array already exists in JSON file" << std::endl;
            return;
        }

        Value array(kArrayType);
        document.AddMember(StringRef(arrayName.c_str()), array, document.GetAllocator());

        StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        document.Accept(writer);

        std::ofstream outfile(path);
        outfile << buffer.GetString();
        outfile.close();
    } else {
        Document document;
        document.SetObject();

        Value array(kArrayType);
        document.AddMember(StringRef(arrayName.c_str()), array, document.GetAllocator());

        StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        document.Accept(writer);

        std::ofstream outfile(path);
        outfile << buffer.GetString();
        outfile.close();
    }
}

std::vector <double> StringToDouble(std::vector <std::string> stringVector) {
    std::vector <double> doubleVector;

    for (const auto& strValue : stringVector) {
        double doubleValue = std::stod(strValue);
        doubleVector.push_back(doubleValue);
    }

    return doubleVector;
}

std::vector <std::string> DoubleToString(const std::vector<double>& input) {
    std::vector <std::string> output(input.size());

    for (int i = 0; i < input.size(); i++) {
        std::ostringstream ss;
        ss << input[i];
        output[i] = ss.str();
    }

    return output;
}