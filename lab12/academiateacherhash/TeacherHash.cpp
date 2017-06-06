//
// Created by prenc on 30.05.17.
//

#include "TeacherHash.h"

namespace academia {

    int TeacherHash::operator()(const Teacher &teacher) const {
        int name_hash = 0, work_hash = 0;
        for (auto &d :teacher.Department()) {
            work_hash += d;
        }
        for (auto &d : teacher.Name()) {
            name_hash += d;
        }
        return teacher.Id() ^ name_hash ^ work_hash;
    }

    bool Teacher::operator==(const Teacher &teacher) const {
        return (id_ == teacher.id_
                && name_ == teacher.name_
                && workplace_ == teacher.workplace_);
    }

    bool Teacher::operator!=(const Teacher &teacher) const { return !(*this == teacher); }

    Teacher::Teacher(const TeacherId &id, const string &name, string workplace) : id_(id), name_(name),
                                                                                  workplace_(workplace) {}

    string Teacher::Name() const { return name_; }

    int Teacher::Id() const { return id_; }


    bool TeacherId::operator!=(const TeacherId &teacher) const { return teacher.id_ != id_; }

    TeacherId::operator int() const { return id_; }

    TeacherId::TeacherId(TeacherId &teacher) : id_(teacher.id_) {}

    TeacherId::TeacherId(int id) : id_(id) {}
}