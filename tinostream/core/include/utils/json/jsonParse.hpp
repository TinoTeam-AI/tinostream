
/* * File with overloaded JsonParse() functions * */
#include "jsonTools.hpp"

#ifdef __cplusplus
extern "C++" {
#endif

namespace tinostream {
    std::vector <std::string> JsonParse(const std::string path, const std::string arrayName);
    void JsonParse(const std::string path, const std::string arrayName, std::vector <std::string> input);
    void JsonParse(const std::string path, const std::string arrayName, std::vector <double> input);
    void JsonParse(const std::string path, const std::string arrayName, std::vector <std::string> input, std::string str);
    void JsonParse(const std::string path, const std::string arrayName, std::vector <double> input, std::string str);
}

#ifdef __cplusplus
}
#endif