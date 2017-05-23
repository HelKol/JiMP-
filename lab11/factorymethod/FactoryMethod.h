//
// Created by prenc on 23.05.17.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>
#include <vector>

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

    template<class T>
    T Mean(std::vector<T> &a){
        T sum= T();
        for(auto &d : a){
            sum+= d;
        }
        return sum/a.size();
    }

    class Repository{
        template<class T>
        T Size(T &input){
            return input.size();
        }

        template<class T>
        int NextId(T &input){
            return input.id+1;
        }

        template<class T>
        T FindBy(T &input){
            return input.size();
        }

        template<class T>
        T operator[](int a) const{
            return this[a];
        }

    };




}
#endif //JIMP_EXERCISES_FACTORYMETHOD_H
