//
// Created by Hela on 12.03.2017.
//
#include <iostream>
#include "Polybius.h"
#include <string>
#include <fstream>
using namespace std;

/*int main(int argc, char **argv)
{
    ifstream myfile("argv[1]");
    if (!myfile)
        cout<< "blad"<<endl;


    if (argv[3]==0)
        std::string PolybiusDecrypt(std::string crypted);
    else
        std::string PolybiusCrypt(std::string message);



}
*/
int main()
{
    std::string a=PolybiusDecrypt("32154343112215");
    cout<<a<<endl;
    return 0;
}