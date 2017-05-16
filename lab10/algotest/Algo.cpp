//
// Created by prenc on 16.05.17.
//

#include <set>
#include <map>
#include <vector>
#include <string>
#include "Algo.h"

namespace algo{
    void CopyInto(std::vector<int> &vector, int &value, std::vector<int> *out) {
        std::copy_n (vector.begin(), value, std::back_inserter(*out));
    }

    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        return std::set<std::string>();
    }

    std::vector<int> Values(const std::map<std::string, int> &m) {
        return std::vector<int>();
    }

    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m, int divisor) {
        return std::map<std::string, int>();
    }

    void SortInPlace(std::vector<int> *v) {

    }

    std::vector<int> Sort(const std::vector<int> &v) {
        return std::vector<int>();
    }

    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {

    }

    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {

    }

    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {

    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> new_one;
        std::string (*foo)(double)= std::to_string;
        std::transform(v.begin(), v.end(), std::back_inserter(new_one), foo);
        return new_one;
    }

    std::string Join(const std::string &joiner, const std::vector<double> &v) {
        return std::__cxx11::string();
    }

    int Sum(const std::vector<int> &v) {
        return 0;
    }

    int Product(const std::vector<int> &v) {
        return 0;
    }

    bool Contains(const std::vector<int> &v, int element) {
        if(std::find(v.begin(), v.end(), element)!= v.end()){
            return true;
        }
        return false;
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        return v.find(key) != v.end();
    }


    bool ContainsValue(const std::map<std::string, int> &v, int value) {
//        return std::find_if(v.begin(), v.end(), [](std::string arg){return v[arg];})!= v.end();
    }

    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v) {
        return std::vector<std::string>();
    }

    void RemoveDuplicatesInPlace(std::vector<std::string> *v) {

    }

    void InitializeWith(int initial_value, std::vector<int> *v) {
        std::fill(v->begin(),v->end(), initial_value);
    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        std::vector<int> tmp;
        std::fill_n(std::back_inserter(tmp), length, initial_value);
        return tmp;
    }

    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length) {
        return 0;
    }
}