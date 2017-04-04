//
// Created by rencpawe on 04.04.17.
//

#include "StudentRepository.h"

namespace academia{
    void StudyYear::operator++() {
        ++year_;
    }

    StudyYear::StudyYear(int year_) : year_(year_) {}
}
