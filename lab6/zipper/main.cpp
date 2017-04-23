//
// Created by xxx on 19.04.17.
//

#include <string>
#include <vector>
#include "Zipper.h"

using std::string;
using std::vector;
using std::pair;

namespace datastructures{
    int foo(const vector<string> &v1, const vector<int> &v2) {
        for (const pair<string,int> &p : Zipper::zip(v1,v2)) {
            if (p.first == "elo") {
                return p.second+4;
            }
        }
        return 0;
    }
}