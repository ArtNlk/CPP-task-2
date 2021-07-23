#include <iostream>
#include <cstdlib>
#include <cstring> //string tools
#include <stdexcept> //invalid_argument
#include <new> //bad alloc

///@brief Replaces all instances of pcszSubstr with pcszStr2 inside of pszResult
///@param pcszSubstr Substring to find and replace
///@param pcszStr2 String that replaces found substring
///@param pszResult Altered string
///@warning This function expects pszResult to have enough memory to house resulting string. String length checks are not performed.
void strreplace(char* pszResult, const char* pcszSubstr, const char* pcszStr2)
{
    if(pszResult == nullptr) throw std::invalid_argument("strreplace: pszResult is NULL");
    if(pcszSubstr == nullptr) throw std::invalid_argument("strreplace: pcszSubstr is NULL");
    if(pcszStr2 == nullptr) throw std::invalid_argument("strreplace: pcszStr2 is NULL");

    if(strstr(pszResult,pcszSubstr) == nullptr) return;

    int substrLength = strlen(pcszSubstr);
    int replStringLength = strlen(pcszStr2);

    size_t bufferAllocLength = strlen(pszResult);
    char* buffer = (char*) calloc(bufferAllocLength,sizeof(char));

    char* currentSubstrPos = nullptr;
    char* currentInputPos = (char*) pszResult;

    char* newBuffer = nullptr;
    size_t preSubstrLength = 9;

    while((currentSubstrPos = strstr(currentInputPos,pcszSubstr)) != nullptr)
    {
        preSubstrLength = currentSubstrPos - currentInputPos;
        if(bufferAllocLength < strlen(buffer) + preSubstrLength + replStringLength)
        {
            bufferAllocLength += preSubstrLength + replStringLength;
            bufferAllocLength *= 2;
            newBuffer = (char*)realloc(buffer,bufferAllocLength);
            if(newBuffer == nullptr)
            {
                free(buffer);
                throw std::bad_alloc();
            }
            buffer = newBuffer;
        }
        strncat(buffer, currentInputPos, preSubstrLength);
        strncat(buffer,pcszStr2,replStringLength);
        currentInputPos = currentSubstrPos + substrLength;
    }

    strncat(buffer,currentInputPos,strlen(currentInputPos));

    strcpy(pszResult,buffer);
    free(buffer);

    return;
}

int main()
{
    char* initString = (char*)calloc(100,sizeof(char));
    strcpy(initString,"ABABCDCDCD-ABABCD__");
    const char* substring = "ABCD";
    const char* replacementString = "0AB";

    std::cout << initString << std::endl;
    strreplace(initString,substring,replacementString);
    std::cout << initString << std::endl;

}
