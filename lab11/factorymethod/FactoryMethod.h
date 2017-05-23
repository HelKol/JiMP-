//
// Created by prenc on 23.05.17.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>

namespace factoryMethod {

    template<class T>
    T Create(){
        return T();
    }

    class MyType{
    public:
        std::string SayHello() {
            return "hello";
        }
    };



}
#endif //JIMP_EXERCISES_FACTORYMETHOD_H
