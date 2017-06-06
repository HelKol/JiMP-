//
// Created by prenc on 30.05.17.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H


template <class Id,class Counter>


class SequentialIdGenerator {
public:
    SequentialIdGenerator() : counter_(0){};
    SequentialIdGenerator(Counter counter) : counter_(counter){};
    Id NextValue(){
        ++counter_;
        return counter_ - 1;};


private:
    Counter counter_;

};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
