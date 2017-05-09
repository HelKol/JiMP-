//
// Created by rencpawe on 09.05.17.
//
#include <string>
#include "Serialization.h"

namespace academia {
    Room::Room(int id, const string &name, academia::Room::Type type) : id(id), name(name), type(type) {}

    std::string NewEnumerableTypeToString(Room::Type type) {
        switch (type) {
            case Room::Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Room::Type::LECTURE_HALL:
                return "LECTURE_HALL";
            case Room::Type::CLASSROOM:
                return "CLASSROOM";
        }
    }


    void Room::Serialize(Serializer *out) {
        out->Header("room");
        out->IntegerField("id", id);
        out->StringField("name", name);
        out->StringField("type", NewEnumerableTypeToString(type));
        out->Footer("room");
    }
}