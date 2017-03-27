//
// Created by xxx on 27.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>

using std::experimental::optional;

namespace nets{
    class JsonValue {
        optional<int> age;
        optional<double> value;
        optional<std::string> name;
        optional<bool> logic;
        optional<std::vector<JsonValue>> js;
        optional<std::map<std::string, JsonValue>> map;

    public:
        JsonValue(int a){age= a;};
        JsonValue(double a){value= a;};
        JsonValue(bool a){logic= a;};
        JsonValue(std::string a){name= a;};
        JsonValue(std::vector<JsonValue> a){js= a;};
        JsonValue(std::map<std::string, JsonValue> a){map= a;};


        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;
    };

}



#endif //JIMP_EXERCISES_SIMPLEJSON_H
