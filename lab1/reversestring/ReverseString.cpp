#include "ReverseString.h"

std::string reverse(std::string str)
{
    std::string new_str="";
    for(int i= 0; i< str.length();i++) new_str= str[i] + new_str;
    return new_str;
}
