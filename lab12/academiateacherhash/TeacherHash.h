//
// Created by prenc on 30.05.17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>

using std::string;

namespace academia {
    class TeacherId {
    public:
        TeacherId(int id);

        TeacherId(TeacherId &teacher);

        operator int() const;

        bool operator!=(const TeacherId &teacher) const;
    private:
        int id_;
    };

    class Teacher {
    public:
        Teacher(const TeacherId &id, const string &name, string workplace);

        bool operator==(const Teacher &teacher) const;

        bool operator!=(const Teacher &teacher) const;

        string Name() const;

        int Id() const;

        string Department() const { return workplace_; };
    private:
        int id_;
        string name_;
        string workplace_;
    };

    class TeacherHash {
    public:
        int operator()(const Teacher &teacher) const;
    };
}


#endif //JIMP_EXERCISES_TEACHERHASH_H
