//
// Created by rencpawe on 11.04.17.
//

#include <vector>
#include <random>
#include "ArrayFill.h"

namespace arrays{
    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }

    int UniformFill::Value(int index) const {
        return value_;
    }

    int IncrementalFill::Value(int index) const {
        return value_+step_*index;
    }

    int RandomFill::Value(int index) const {
        return (*distribution)(*generator);
    }

    int SquaredFill::Value(int index) const {
        return a_*index*index+b_;
    }
}