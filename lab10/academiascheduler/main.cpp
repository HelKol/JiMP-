//
// Created by prenc on 21.05.17.
//

#include <iostream>
#include "Scheduler.h"
using namespace academia;
using std::vector;
using std::map;
using std::set;

int main(void){
    vector<int> rooms{1000};
    
    map<int, vector<int>> teachers{make_pair(100, vector<int>{10, 20}), make_pair(200, vector<int>{30}),
                                   make_pair(300, vector<int> {40})};
    
    map<int, set<int>> years{make_pair(1, set<int>{10, 20}), make_pair(2, set<int>{30, 40})};
    
    for(auto d:rooms){
        std::cout<<d<<" ";
    }
}