//
// Created by prenc on 30.05.17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

namespace academia{
    class Teacher{

    };
    class TeacherId{
    public:
        TeacherId(int a): a_(a){};
        int a_;
        int operator=(int a){return a_;};
    };
    class TeacherHash{

    };
}


#endif //JIMP_EXERCISES_TEACHERHASH_H
