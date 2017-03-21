//
// Created by xxx on 21.03.17.
//
#include <regex>
#include "SimpleUrl.h"
namespace nets{
    std::string SimpleUrl::Login() const {
        std::smatch matches;
        if (regex_match(url, matches, regex)){
            return matches[3];
        }

    }

    std::string SimpleUrl::Host() const {
        std::smatch matches;
        if (regex_match(url, matches, regex)){
            return matches[3];
        }
    }

    std::string SimpleUrl::Path() const {
        std::smatch matches;
        if (regex_match(url, matches, regex)){
            return matches[3];
        }
    }

    uint16_t SimpleUrl::Port() const {
        std::smatch matches;
        if (regex_match(url, matches, regex)){
            return matches[3];
        }
    }

    std::string SimpleUrl::Scheme() const {
        std::smatch matches;
        if (regex_match(url, matches, regex)){
            return matches[1];
        }
    }

    std::string SimpleUrl::Query() const {
        std::smatch matches;
        if (regex_match(url, matches, regex)){
            return matches[3];
        }
    }

    std::string SimpleUrl::Fragment() const {
        std::smatch matches;
        if (regex_match(url, matches, regex)){
            return matches[3];
        }
    }
}