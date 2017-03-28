//
// Created by rencpawe on 14.03.17.
//
#include <sstream>
#include <regex>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include "MinimalTimeDifference.h"


using ::std::string;
using ::std::stringstream;
using ::std::regex;
using ::std::smatch;
using ::std::vector;
using ::std::sort;

namespace minimaltimedifference {


    int ToInt(string value) {
        stringstream ss;
        int output;
        ss << value;
        ss >> output;
        return output;
    }

    unsigned int ToMinutes(std::string time_HH_MM) {
        int output;
        regex pattern{R"((\d{1,2}):(\d{2}))"};
        smatch matches;
        if (regex_match(time_HH_MM, matches, pattern)) {
            output = ToInt(matches[1]) * 60 + ToInt(matches[2]);
        }
        return output;
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times) {
        vector<int> new_v;
        int min= 24*60;
        for(auto n:times){
            new_v.emplace_back(ToMinutes(n));
        }
        sort(new_v.begin(),new_v.end());
        for(int i=0;i<new_v.size()-1;i++){
            int tmp= new_v[i+1]-new_v[i];
            if (tmp<min) min=tmp;
        }
        int tmp= 24*60 -(new_v.back()-new_v[0]);
        if (tmp<min) min=tmp;

        return min;
    }
};