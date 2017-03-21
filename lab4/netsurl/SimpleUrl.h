//
// Created by xxx on 21.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEURL_H
#define JIMP_EXERCISES_SIMPLEURL_H

#include <string>
#include <cstdint>

namespace nets{
    class SimpleUrl {

        std::string Login() const;
        std::string Host() const;
        std::string Path() const;
        uint16_t Port() const;
        std::string Scheme() const;
        std::string Query() const;
        std::string Fragment() const;
    };
}

#endif //JIMP_EXERCISES_SIMPLEURL_H
