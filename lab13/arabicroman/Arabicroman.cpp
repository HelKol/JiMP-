//
// Created by prenc on 06.06.17.
//

#include <map>
#include "Arabicroman.h"

std::string arabicroman::ArabicToRoman(int a) {return "";  }

int arabicroman::RomanToArabic(std::string a) {

        std::map<char,int> value={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int sum=0; char prev='%';
        for(int i=(a.length()-1); i>=0; i--)
        {
            if(value[a[i]]<sum && (a[i]!=prev))
            {       sum -= value[a[i]];
                prev = a[i];
            }
            else
            {
                sum += value[a[i]];
                prev = a[i];
            }
        }
        return sum;

}

