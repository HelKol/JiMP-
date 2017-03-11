//
// Created by ubuntu on 3/11/17.
//

#include "Polybius.h"


std::string PolybiusCrypt(std::string message)
{
    std::string code="abcdefghiklmnopqrstuvwxyz";
    std::string output="";
    int i;

    for(char n : message)
    {
        if(n<=90 and n > 64) n+=32;
        if(n=='j') n='i';
        for (i=0;i<code.length();i++)
        {
            if(n==code[i]) break;
        }

        if(n!=' ') output+= std::to_string((i/5)+1)+std::to_string(i%5+1);
    }

    return output;
}
std::string PolybiusDecrypt(std::string crypted)
{
    std::string code="abcdefghiklmnopqrstuvwxyz";
    std::string output="";
    int i;

    for(int d=0;d<crypted.length();d+2)
    {
        output+= code[std::stoi(crypted[d])*5+std::stoi(crypted[d+1])-1];
    }

    return output;
}