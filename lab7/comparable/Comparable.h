//
// Created by rencpawe on 11.04.17.
//

#ifndef JIMP_EXERCISES_COMPARABLE_H
#define JIMP_EXERCISES_COMPARABLE_H

#include <string>
namespace academia{
    class Student{
    private:
        std::string first_name;
        std::string last_name;
    };
    class StudentComparator{
    public:

        virtual bool IsLess(const Student &left, const Student &right);
    };


}


#endif //JIMP_EXERCISES_COMPARABLE_H
