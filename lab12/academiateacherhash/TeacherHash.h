//
// Created by prenc on 30.05.17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H
#include <string>

using std::string;

namespace academia{
    class TeacherId{
    public:
        TeacherId( int id): id_(id){};
        operator int() {return id_;};
    private:
        int id_;
    };
    class Teacher{
        Teacher(TeacherId &id, string &name,string workplace):id_(id),name_(name),workplace_(workplace){
        }
        string Name() {return name_;};
        TeacherId Id(){return id_;};

    private:
        TeacherId id_;
        string name_;
        string workplace_;


    };

    class TeacherHash{
    public:
        TeacherHash(){};
        int operator () ( Teacher teacher){
            return 0;
        };
    };
}


#endif //JIMP_EXERCISES_TEACHERHASH_H
