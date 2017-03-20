//
// Created by xxx on 18.03.17.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <map>
#include <string>
#include <array>
#include <memory>

namespace tinyurl {
    struct TinyUrlCodec{
        std::map<std::string, std::string> v;
        TinyUrlCodec(){
            v.emplace("000000","none");
        }
    };

    std::unique_ptr<TinyUrlCodec> Init();
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}

#endif //JIMP_EXERCISES_TINYURL_H
