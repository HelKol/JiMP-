//
// Created by ubuntu on 3/6/17.
//

#include "Palindrome.h"

bool is_palindrome(std::string str)
{
    for(int i=0; i<str.length()/2;i++)
        if(str[i]!=str[str.length()-i-1])
            return false;
    return true;
}