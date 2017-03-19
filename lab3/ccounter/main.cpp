//
// Created by rencpawe on 14.03.17.
//
#include <iostream>
#include "CCounter.h"
using namespace ccounter;
using std::cout;
using std::endl;

int main(void){
    std::unique_ptr<Counter> counter = Init();
    Inc("a", &counter);
    Inc("a", &counter);
    Inc("a", &counter);
    Inc("a", &counter);

    bool first = true;
    for(const auto &n : counter->v) {
        if (!first) {
            cout<<endl;
        } else {
            first = false;
        }
        cout << n.first << " -> " << n.second;
    }
    cout<<endl;
    cout<<Counts(counter, "a")<<endl;

    return 0;
}