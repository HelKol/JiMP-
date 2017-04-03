//
// Created by xxx on 02.04.17.
//

#include "TextPool.h"


namespace pool{
    TextPool::TextPool() {

    }

    TextPool::TextPool(const std::initializer_list<std::experimental::string_view> &elements) {
        this->elements= elements;
    }

    TextPool::TextPool(TextPool &&xxx) {

    }

    TextPool &TextPool::operator=(TextPool &&xxx) {

    }

    TextPool::~TextPool() {
    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        return std::experimental::string_view();
    }

    size_t TextPool::StoredStringCount() const {
        return elements.size();
    }
}