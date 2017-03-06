#include "ReverseString.h"



std::string reverse(std::string word)
{
    std::string new_word="";
    for(int i=0; i< word.length();i++) new_word= word[i] + new_word;
    return new_word;
}