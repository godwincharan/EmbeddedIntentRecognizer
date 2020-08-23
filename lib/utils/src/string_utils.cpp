#include "string_utils.h"
#include <sstream>

namespace utils
{
void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

const std::vector<std::string> GetTokens(const std::string& state_line, const char& delim)
{
    std::vector<std::string> tokens;
    std::stringstream state_line_stream(state_line); 
    std::string token; 
    while(getline(state_line_stream, token, delim)) 
    {
        utils::trim(token);
        if ( !token.empty())
        {
            tokens.push_back(token);
        } 
    }
    return tokens;
}
} // utils
