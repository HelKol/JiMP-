//
// Created by rencpawe on 09.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZER_H
#define JIMP_EXERCISES_SERIALIZER_H

#include <string>
#include <vector>

using std::string;

namespace academia{
    class Serializer;
    class Serializable{
    public:
        virtual void Serialize(Serializer *out)=0;
    };

    class Serializer {
    public:

        Serializer(std::ostream *out) : out_(out) {}

        virtual void Header(const string &str)=0;

        virtual void IntegerField(const string &str, int value)=0;

        virtual void DoubleField(const string &str, double value)=0;

        virtual void
        ArrayField(const string &str, const std::vector<std::reference_wrapper<const Serializable>> &value)=0;

        virtual void SerializableField(const string &str, const Serializable &value)=0;

        virtual void BooleanField(const string &str, bool value)=0;

        virtual void StringField(const string &str, const string &value)=0;

        virtual void Footer(const string &str)=0;

        virtual ~Serializer() {};
    private:
        std::ostream *out_;
    };
    class Room : public Serializable{
    public:

        enum class Type {COMPUTER_LAB, LECTURE_HALL, CLASSROOM};

        Room(int id, const string &name, Type type);

        void Serialize(Serializer *out) override;

    private:
        int id;
        string name;
        Type type;
    };

    class Building : public Serializable{
    public:
    private:
        std::vector<Room> list;
    };
}



#endif //JIMP_EXERCISES_SERIALIZER_H
