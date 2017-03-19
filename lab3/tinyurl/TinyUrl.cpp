//
// Created by xxx on 18.03.17.
//
#include <utility>
#include <string>
#include <array>
#include <memory>
#include "TinyUrl.h"

namespace tinyurl{
    std::unique_ptr<TinyUrlCodec> Init() {
        return std::unique_ptr<TinyUrlCodec>(new TinyUrlCodec);
    }

    void NextHash(std::array<char, 6> *state) {
        std::string code="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        int i=5;
        while(i>=0){
            for(int d=0;d<62;d++){
                if(code[d]==(*state)[i]){
                    if(d!=61){
                        (*state)[i]= code[d+1];
                        i=0;
                        break;
                    } else {
                        (*state)[i]= '0';
                    }
                }
            }
            i--;
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
        std::string hash;
        return url;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {

        return hash;
    }
}