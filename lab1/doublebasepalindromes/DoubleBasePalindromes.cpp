//
// Created by ubuntu on 3/6/17.
//

#include "DoubleBasePalindromes.h"

bool palindrome(std::string str)
{
    for(int i=0; i<str.length()/2;i++)
        if(str[i]!=str[str.length()-i-1])
            return false;
    return true;
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive)
{
    if (max_vaule_exculsive< 0) return 0;
    int sum;
    for(int i= 0; i<max_vaule_exculsive;i++)
    {
        std::string tmp="";
        int w= i;
        while(w>0)
        {
            tmp= std::to_string(w%2) + tmp;
            w/=2;
        }

        if (palindrome(std::to_string(i)) and palindrome(tmp)) sum+=i;
    }
    return sum;
}