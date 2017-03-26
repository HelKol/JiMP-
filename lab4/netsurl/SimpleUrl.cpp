//
// Created by xxx on 21.03.17.
//
#include <regex>
#include "SimpleUrl.h"
namespace nets{
    std::string SimpleUrl::Login() const {
        std::smatch matches;
        if (regex_match(url, matches, regex)){
            return matches[SimpleUrl::login];
        }

    }

    std::string SimpleUrl::Host() const {
        std::smatch matches;
        if (regex_match(url, matches, regex)){
            return matches[SimpleUrl::host];
        }
    }

    std::string SimpleUrl::Path() const {
        std::smatch matches;
        if (regex_match(url, matches, regex)){
            return matches[SimpleUrl::path];
        }
    }

    uint16_t SimpleUrl::Port() const {
        std::smatch matches;

        if (regex_match(url, matches, regex)){
            if(matches[SimpleUrl::port]!=""){
                return stoi(matches[SimpleUrl::port]);
            }
            else if(matches[SimpleUrl::sheme]=="https") return 443;
            else if (matches[SimpleUrl::sheme]=="http") return 80;
            else if (matches[SimpleUrl::sheme]=="ftp") return 22;
            else return 0;
        }
    }

    std::string SimpleUrl::Scheme() const {
        std::smatch matches;
        if (regex_match(url, matches, regex)){
            return matches[SimpleUrl::sheme];
        }
    }

    std::string SimpleUrl::Query() const {
        std::smatch matches;
        if (regex_match(url, matches, regex)){
            return matches[SimpleUrl::query];
        }
    }

    std::string SimpleUrl::Fragment() const {
        std::smatch matches;
        if (regex_match(url, matches, regex)){
            return matches[SimpleUrl::fragment];
        }
    }
}