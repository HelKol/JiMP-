//
// Created by prenc on 16.05.17.
//

#include "Algo.h"

namespace algo{
    CopyInto::CopyInto(std::vector<int> &vector, int &value, std::vector<int> *out) {
        std::copy_n (vector.begin(), value, std::back_inserter(*out));
    }

//    Contains::Contains(const std::vector<int> &v, int element) {
//
//    }
}