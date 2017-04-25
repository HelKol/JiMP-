//
// Created by Hela on 10.04.2017.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H
#include <string>
#include <vector>

using std::string;
using std::vector;

string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<std::string> &dictionary);
string Binary(int dec);
string FindKey( std::vector<std::string> dictionary, std::vector<char> cryptogram);
string Ascii(char letter);
vector<string> Decrypted( std::vector<char> cryptogram, string key);
bool Check(vector<string> decrypted ,const std::vector<std::string> dictionary);
vector<int> BinaryToAsciiToLetter(vector<string> decrypted);
vector <string> AllWords(vector <int> ascii_letters);




#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
