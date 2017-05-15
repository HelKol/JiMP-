//
// Created by rencpawe on 09.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZER_H
#define JIMP_EXERCISES_SERIALIZER_H

#include <string>
#include <vector>
#include <sstream>
#include <experimental/optional>

using std::vector;
using std::string;

namespace academia{
    class Serializer;

    class Serializable{
    public:
        virtual void Serialize(Serializer *out) const=0;
    };

    class Serializer {
    public:
        std::ostream *out_;

        Serializer(){}

        Serializer(std::ostream *out) : out_(out) {}

        virtual void Header(const string &str)=0;

        virtual void IntegerField(const string &str, int value)=0;

        virtual void DoubleField(const string &str, double value)=0;

        virtual void ArrayField(const string &str, const vector<std::reference_wrapper<const Serializable>> &value)=0;

        virtual void SerializableField(const string &str, const Serializable &value)=0;

        virtual void BooleanField(const string &str, bool value)=0;

        virtual void StringField(const string &str, const string &value)=0;

        virtual void Footer(const string &str)=0;
    };
    class Room : public Serializable{
    public:
        enum class Type {COMPUTER_LAB, LECTURE_HALL, CLASSROOM};
        Room(int id, const string &name, Type type);
        void Serialize(Serializer *out) const override;
    private:
        int id_;
        string name_;
        Type type_;
    };

    class Building : public Serializable{
    public:
        int Id() const;
        void Serialize(Serializer *out) const override;
        Building(int id, string name, vector<Room> list);
    private:
        vector<Room> list_;
        string name_;
        int id_;
    };

    class JsonSerializer : public Serializer{
    public:
        JsonSerializer(std::ostream *out) : Serializer(out){}

        void Header(const string &str) override;

        void IntegerField(const string &str, int value) override;

        void DoubleField(const string &str, double value) override;

        void ArrayField(const string &str, const vector<std::reference_wrapper<const Serializable>> &value) override;

        void SerializableField(const string &str, const Serializable &value) override;

        void BooleanField(const string &str, bool value) override;

        void StringField(const string &str, const string &value) override;

        void Footer(const string &str) override;

    };
    class XmlSerializer : public Serializer{
    public:
        XmlSerializer(std::ostream *out) : Serializer(out){}

        void Header(const string &str) override;

        void IntegerField(const string &str, int value) override;

        void DoubleField(const string &str, double value) override;

        void ArrayField(const string &str, const vector<std::reference_wrapper<const Serializable>> &value) override;

        void SerializableField(const string &str, const Serializable &value) override;

        void BooleanField(const string &str, bool value) override;

        void StringField(const string &str, const string &value) override;

        void Footer(const string &str) override;

    };

    class BuildingRepository
    {
    public:
        BuildingRepository(){};
        BuildingRepository(const std::initializer_list<Building> &building);
        std::experimental::optional<Building> operator[](int id) const;
        void Add(const Building &building);
        void StoreAll(Serializer *serializer) const;
    private:
        vector<Building> list_;
    };
}

#endif //JIMP_EXERCISES_SERIALIZER_H
