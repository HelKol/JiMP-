//
// Created by rencpawe on 14.03.17.
//
#include <string>
#include <memory>
#include <map>
#include "CCounter.h"


namespace ccounter {


    std::unique_ptr<Counter> Init() {
        return std::unique_ptr<Counter>(new Counter);
    }

    void Inc(std::string key, std::unique_ptr<Counter> *counter) {
        bool found= false;
        for(auto &n : (*counter)->v){
            if(n.first== key) {
                n.second++;
                found = true;
                break;
            }
        }
        if(!found){
            (*counter)->v.emplace(key, 1);
        }
    }

    int Counts(const std::unique_ptr<Counter> &counter, std::string key) {
        for(auto n : counter->v){
            if(n.first==key) return n.second;
        }
        return 0;
    }

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter) {
        for(auto n : (*counter)->v) {
            if (n.first == key) n.second= value;
        }
    }
}