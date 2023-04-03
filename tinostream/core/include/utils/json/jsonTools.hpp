
#include "rapidjson/stringbuffer.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"

#pragma once
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

using namespace rapidjson;

#ifdef __cplusplus
extern "C++" {
#endif

// Function to read values from a JSON array
std::vector <std::string> readJSON(std::string path, std::string arrayName);

// Function to write values to json array
void writeJSON(std::string path, std::vector <std::string> input, std::string arrayName);

// A function for writing values to a json array, while all its contents are erased
void writeJSONdel(std::string path, std::vector<std::string> input, std::string arrayName);

// Function to create a new JSON file or add an array to an existing JSON file
void CheckJSON(std::string path, std::string arrayName);

std::vector <double> StringToDouble(std::vector <std::string> stringVector);
std::vector <std::string> DoubleToString(const std::vector<double>& input);

#ifdef __cplusplus
}
#endif