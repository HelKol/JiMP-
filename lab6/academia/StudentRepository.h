//
// Created by rencpawe on 04.04.17.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <string>


namespace academia {
    class Student{
    private:
        std::string id_;
        std::string first_name_;
        std::string last_name_;
        std::string program_;
        StudyYear year_;
    };
    class StudyYear {
        void operator++(StudyYear&);
    private:
        int year_;
    };
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
