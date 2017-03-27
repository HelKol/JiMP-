//
// Created by xxx on 27.03.17.
//
#include <sstream>
#include <regex>
#include "SimpleJson.h"
namespace nets{
    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {

    }

    std::string JsonValue::ToString() const {
        if (age) return std::to_string(*age);
//        if (name) return "\"" + *name + "\"";
//        if (value) {
//            std::regex regex{R"((\d+\.\d*[1-9])0*)"};
//            std::smatch matches;
//            std::string str = std::to_string(*value);
//            if (std::regex_match(str, matches, regex)) {
//                return matches[1];
//            }
//        }
//        if (logic) {
//            if (*logic== true) return "true";
//            else return "false";
//        }
//        if(js){
//
//        }


    }
}