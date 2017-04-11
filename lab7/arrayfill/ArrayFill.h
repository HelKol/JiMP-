//
// Created by rencpawe on 11.04.17.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <vector>
#include <stdio.h>
#include <memory>

namespace arrays {
    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };


    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}

        virtual int Value(int index) const override;

    private:
        int value_;
    };

    class IncrementalFill : public ArrayFill{
    public:
        IncrementalFill(int start= 0, int step= 1) : value_{start},step_{step}{}
        virtual int Value(int index) const override;
    private:
        int value_;
        int step_;
    };

    class RandomFill : public ArrayFill{
    public:
        RandomFill(std::unique_ptr<std::default_random_engine> generator,
                   std::unique_ptr<std::uniform_int_distribution<int>> distribution) : generator{move(generator)},distribution{move(distribution)}{}
        virtual int Value(int index) const override;
    private:
        std::unique_ptr<std::uniform_int_distribution<int>> distribution;
        std::unique_ptr<std::default_random_engine> generator;
    };

    class SquaredFill : public ArrayFill{
    public:
        SquaredFill(int a= 1, int b= 0) : a_{a}, b_{b}{}
        virtual int Value(int index) const override;
    private:
        int a_;
        int b_;
    };

}
#endif //JIMP_EXERCISES_ARRAYFILL_H
