//
// Created by Hela on 10.04.2017.
//

#include "XorCypherBreaker.h"
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iostream>

using std::find;
using std::vector;
using std::string;

string Binary(int dec)
{
    std::string bin;
    while(dec!=0) {
        int tmp = dec%2;
        if (tmp==0)
            bin="0"+bin;
        else
            bin="1"+bin;
        dec=floor(dec/2);

    }
    while (bin.length()<8)
        bin="0"+bin;
        return bin;
}

string Ascii(char letter){
    int ascii=letter;
    string str_ascii;
    str_ascii=Binary(ascii);
    while (str_ascii.length()<8)
        str_ascii="0"+str_ascii;
    return str_ascii;
}

vector<int> BinaryToAsciiToLetter(vector<string> decrypted){
    vector <int> letters;
    string str;
    int ascii;
    int tmp=0;
    for (int i=0;i<decrypted.size();i++){
        str=decrypted[i];
        ascii=0;
        for (int j=0; j<str.length();j++){
             if (str[j]=='0')
                tmp=0;
            else
                tmp=1;
            ascii=ascii*2+tmp;
        }
        letters.push_back(ascii);
    }
    return letters;

}

char Xor(char first, char second){
//    int num_d;
//    int num_k;
//    int xor_result;
//
//    if (second=='0')
//        num_k=0;
//    else
//        num_k=1;
//
//    if (second=='0')
//        num_d=0;
//    else
//        num_d=1;
    int x_or = first xor second;
    if (x_or==1)
        return '1';
    else if (x_or==0)
        return '0';
    else
        return (' ');
}

vector<string> Decrypted( std::vector<char> cryptogram, string key){
    vector<string> decrypted;
    string bin_str="";
    string end_str="";
    char xor_result;

    for (int i=0;i<cryptogram.size();i++){
        char str=cryptogram[i];
        bin_str="";
        end_str="";
        bin_str=Binary(str);
        for (int j =0;j<bin_str.length();j++){
            xor_result=Xor(bin_str[j],key[j]);
            end_str+=xor_result;

        }
        std::cout<<bin_str<<" ";
        decrypted.push_back(end_str);
    }
    return decrypted;
}

vector <string> AllWords(vector <int> ascii_letters){
    vector <string> all_words;
    char letter;
    string word=" ";
    int brrr;
    for (int i=0;i<ascii_letters.size(); i++){
        if ((91>ascii_letters[i] && ascii_letters[i]>64) || (123>ascii_letters[i] && ascii_letters[i]>96)) {

            brrr=ascii_letters[i];
            letter = brrr;
            word += letter;
        }
        else
        {   if (word!="")
                all_words.push_back(word);
            word="";
        }
    }

    return all_words;
}



bool Check(vector<string> all_words ,const std::vector<std::string> dictionary){

    int ok_words = 0;
    string word;
    for (int i=0;i<all_words.size();i++){
        word=all_words[i];
        if (find(dictionary.begin(), dictionary.end(), word) != dictionary.end())
            ok_words += 1;
}
    if (ok_words>3)
        return true;
    else
    return false;
}

string FindKey( std::vector<std::string> dictionary, std::vector<char> cryptogram){
    string alphabet= "abcdefghijklmnopqrstuvwxyz";
    string key;
    vector <int> tmp;
    for (int i=0;i<26;i++){
        for (int j=0;j<26;j++){
            for (int k=0;k<26;k++){
                key=Ascii(alphabet[i]);
                key+=Ascii(alphabet[j]);
                key+=Ascii(alphabet[k]);
                tmp=BinaryToAsciiToLetter(Decrypted(cryptogram,key));
                if (Check(AllWords(tmp),dictionary))
                    return key;
            }
        }
    }
}

std::string XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<string> &dictionary) {
    string key;

    key = FindKey(dictionary,cryptogram);
    int tmp, ascii;
    ascii=0;
    string word;
    for (int j=0; j<key.length();j++){
        if (key[j]=='0')
            tmp=0;
        else
            tmp=1;
        ascii=ascii*2+tmp;
    }

    return key;
}
