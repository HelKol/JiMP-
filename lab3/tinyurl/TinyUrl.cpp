//
// Created by xxx on 18.03.17.
//
#include <iostream>
#include <utility>
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
        std::string last= (*codec)->v.rbegin()->first;
        std::array<char, 6> tmp;
        for (int i=0; i<6; i++) {
            tmp[i]=last[i];
        }
        NextHash(&tmp);
        for (int d=0; d<6; d++) hash+=tmp[d];
        (*codec)->v.emplace(hash, url);
        return hash;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
        std::string output;
        for (auto n : codec->v) {
            if (n.first== hash){
                output= n.second;
            }
        }
        return output;
    }
}