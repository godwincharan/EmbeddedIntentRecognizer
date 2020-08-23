#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <vector>

namespace utils
{
void ltrim(std::string &s);
void rtrim(std::string &s);
void trim(std::string &s);
const std::vector<std::string> GetTokens(const std::string& state_line, const char& delim);
} // utils
#endif // STRING_UTILS_H
