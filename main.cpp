#include <iostream>
#include <cstdlib>
#include <cstring>
#include <exception>

///@brief Replaces all instances of pcszSubstr with pcszStr2 inside of pszResult
///@param pcszSubstr Substring to find and replace
///@param pcszStr2 String that replaces found substring
///@param pszResult Altered string
void strreplace(char* pszResult, const char* pcszSubstr, const char* pcszStr2)
{
    if(pszResult == nullptr) throw std::invalid_argument("strreplace: pszResult is NULL");
    if(pcszSubstr == nullptr) throw std::invalid_argument("strreplace: pcszSubstr is NULL");
    if(pcszStr2 == nullptr) throw std::invalid_argument("strreplace: pcszStr2 is NULL");

    int substrLength = strlen(pcszSubstr);
}

int main()
{

}
