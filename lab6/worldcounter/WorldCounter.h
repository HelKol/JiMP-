//
// Created by xxx on 23.04.17.
//

#ifndef JIMP_EXERCISES_WORLDCOUNTER_H
#define JIMP_EXERCISES_WORLDCOUNTER_H

#include <string>
#include <vector>
#include <set>

namespace datastructures{
    class Counts{
    public:
        Counts(int a);
        Counts();
        int GetCounts();
        void SetCounts(int a);

        bool operator<(Counts a);
        bool operator>(Counts a);
        bool operator==(Counts a);
        bool operator==(int value);
        Counts* operator++(int);
    private:
        int number;

    };

    class Word{
    public:
        Word(std::string word);
        std::string GetWord() const;

        bool operator<(const Word &a) const;
        bool operator>(const Word &a) const;
        bool operator<=(const Word &a) const;
        bool operator>=(const Word &a) const;
        bool operator==(const Word &a) const;
    private:
        std::string word;
    };

    class WorldCounter {
    public:
        WorldCounter(std::initializer_list<datastructures::Word> ll);

        void FromInputStream(std::ifstream &input);
        int DistincWord();
        int TotalWords();
        std::set<datastructures::Word> Words();
        std::vector<std::pair<datastructures::Word, datastructures::Counts>> GetSet() const;

        int operator[](std::string word);

    private:
        std::vector<std::pair<datastructures::Word, datastructures::Counts>> input;
    };


    ostream &operator<<(ostream &op, WorldCounter &a);
}



#endif //JIMP_EXERCISES_WORLDCOUNTER_H
