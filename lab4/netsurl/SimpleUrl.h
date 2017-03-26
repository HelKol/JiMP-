//
// Created by xxx on 21.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEURL_H
#define JIMP_EXERCISES_SIMPLEURL_H

#include <regex>
#include <string>
#include <cstdint>

namespace nets{
    class SimpleUrl {
        public:
            enum trelemorele{sheme= 1, login= 4, host= 5, port= 7, path= 9, query= 11, fragment= 13};
            std::string url;
            std::regex regex {R"(^([a-zA-z]+):(\/\/)?(([a-z\.]+)@)?([a-z\.-]+)(:([0-9]+))?(\/([^#?\n]*))?(\?([^#\n]+))?(#([^\n]+)?)?)"};
            SimpleUrl(std::string value){
                url= value;
            }
            std::string Login() const;
            std::string Host() const;
            std::string Path() const;
            uint16_t Port() const;
            std::string Scheme() const;
            std::string Query() const;
            std::string Fragment() const;
    };
}

#endif //JIMP_EXERCISES_SIMPLEURL_H
