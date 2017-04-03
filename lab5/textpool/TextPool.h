//
// Created by xxx on 02.04.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>


namespace pool {

    class TextPool {
    public:
        TextPool();
        TextPool(const std::initializer_list<std::experimental::string_view> &elements);

        TextPool(const TextPool &xxx)= delete;
        TextPool(TextPool &&xxx);
        TextPool &operator=(const TextPool &xxx)= delete;
        TextPool &operator=(TextPool &&xxx);
        ~TextPool();

        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

    private:
        std::initializer_list<std::experimental::string_view> elements;
    };

}
#endif //JIMP_EXERCISES_TEXTPOOL_H
