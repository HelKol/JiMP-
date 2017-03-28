//
// Created by xxx on 27.03.17.
//
#include <sstream>
#include <regex>
#include "SimpleJson.h"
namespace nets{
    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        for (auto n : *map) {
            if (n.first== name){
//                return n.second;
            }
        }
    }

    std::string JsonValue::ToString() const {
        if (age) return std::to_string(*age);
        if (name){
            std::string output= *name;
            for(int i=0; i<output.length();i++){
                if(output[i]=='\\' || output[i]=='\"') {
                    output.insert(i,"\\");
                    i++;
                }
            }
            return "\"" + output + "\"";
        }
        if (value) {
            std::regex regex{R"((-?\d+\.\d*[1-9])0*)"};
            std::smatch matches;
            std::string str = std::to_string(*value);
            if (std::regex_match(str, matches, regex)) {
                return matches[1];
            }
        }
        if (logic) {
            if (*logic== true) return "true";
            else return "false";
        }
        if(js){
            std::string output;
            for( auto &n : *js){
                output+= n.ToString() + ", ";
            }
            output=output.substr(0,output.length()-2);

            return "["+output+"]";
        }
        if(map){
            std::string output;
            for( auto n : *map){
                std::string tmp= n.first;
                for(int i=0; i<tmp.length();i++){
                    if(tmp[i]=='\\' || tmp[i]=='\"') {
                        tmp.insert(i,"\\");
                        i++;
                    }
                }
                output+= "\""+tmp+"\": "+n.second.ToString()+", ";
            }
            output=output.substr(0,output.length()-2);

            return "{"+output+"}";
        }

        return "0";
    }
}
