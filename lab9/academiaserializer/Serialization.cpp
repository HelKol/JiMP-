//
// Created by rencpawe on 09.05.17.
//

#include <string>
#include <functional>
#include <iostream>
#include "Serialization.h"

namespace academia{
    Room::Room(int id, const string &name, academia::Room::Type type) : id_(id), name_(name), type_(type){}

    Building::Building(int id, string name,vector<Room> rooms):id_(id), name_(name), list_(rooms) {}
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


    void Room::Serialize(Serializer *out) const {
        out->Header("room");
        out->IntegerField("id", id_);
        out->StringField("name", name_);
        out->StringField("type", NewEnumerableTypeToString(type_));
        out->Footer("room");
    }


    void Building::Serialize(Serializer *out) const {
        out->Header("building");
        out->IntegerField("id",id_);
        out->StringField("name",name_);
        std::vector<std::reference_wrapper<const Serializable>> tmp;
        for(const auto &d : list_)
        {
            tmp.emplace_back(std::cref(d));
        }
        out->ArrayField("rooms",tmp);
        out->Footer("building");
    }

    void JsonSerializer::Header(const string &str){
        *out_<<"{";
    }

    void JsonSerializer::Footer(const string &str){
        *out_<<"}";
        }

    void JsonSerializer::IntegerField(const string &str, int value){
        *out_<<"\""<<str<<"\": "<<value<<", ";
    }

    void JsonSerializer::DoubleField(const string &str, double value){
        *out_<<"\""<<str<<"\": "<<value<<", ";
    }

    void JsonSerializer::StringField(const string &str, const string &value){
        if(str=="type"){
            *out_<<"\""<<str<<"\": \""<<value<<"\"";
        } else{
            *out_<<"\""<<str<<"\": \""<<value<<"\", ";
        }

    }


    void JsonSerializer::BooleanField(const std::string &str, bool value) {
        *out_<<"\""<<str<<"\": \""<<value<<"\"";
    }

    void JsonSerializer::SerializableField(const std::string &str, const academia::Serializable &value) {}

    void JsonSerializer::ArrayField(const std::string &str,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value){
        *out_<<"\""<<str<<"\": [";
        int counter=0;
        for(const Serializable &d : value)
        {
            counter++;
            d.Serialize(this);
            if(counter!= value.size()) *out_<<", ";
        }
        *out_<<"]";
    }




    void XmlSerializer::Header(const string &str){
        *out_<<"<"<<str<<">";
    }

    void XmlSerializer::Footer(const string &str){
        *out_<<"<\\"<<str<<">";
    }

    void XmlSerializer::IntegerField(const string &str, int value){
        *out_<<"<"<<str<<">"<<value<<"<\\"<<str<<">";
    }

    void XmlSerializer::DoubleField(const string &str, double value){
        *out_<<"<"<<str<<">"<<value<<"<\\"<<str<<">";
    }

    void XmlSerializer::StringField(const string &str, const string &value){
        *out_<<"<"<<str<<">"<<value<<"<\\"<<str<<">";

    }

    void XmlSerializer::BooleanField(const std::string &str, bool value){
        *out_<<"<"<<str<<">"<<value<<"<\\"<<str<<">";
    }

    void XmlSerializer::SerializableField(const std::string &str, const academia::Serializable &value) {}

    void XmlSerializer::ArrayField(const std::string &str,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value){
        *out_<<"<"<<str<<">";
        for(const Serializable &d:value)
        {
            d.Serialize(this);
        }
        *out_<<"<\\"<<str<<">";
    }

    int Building::Id() const {
        return id_;
    }

    void BuildingRepository::StoreAll(Serializer *serializer) const {
        serializer->Header("building_repository");
        std::vector<std::reference_wrapper<const Serializable>> tmp;
        for(const auto &n : list_)
        {
            tmp.emplace_back(std::cref(n));
        }
        serializer->ArrayField("buildings",tmp);
        serializer->Footer("building_repository");
    }

    void BuildingRepository::Add(const Building &building) {
        list_.emplace_back(building);
    }

    BuildingRepository::BuildingRepository(const std::initializer_list<Building> &building) {
        for(const auto &n : building)
        {
            this->list_.emplace_back(n);
        }
    }

    std::experimental::optional<Building> BuildingRepository::operator[](int id) const {
        for (auto const &building : list_) {
            if (building.Id() == id) {
                return std::experimental::make_optional(building);
            }
        }
        return std::experimental::optional<Building>();
    }
}