//
// Created by kolahele on 21.03.17.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H
#include "Point.h"
#include <cmath>
#include <ostream>


using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

namespace geometry{
    class Square {
    public:
        Square(const Point &lu, const Point &lb, const Point &ru, const Point &rb);
        Point lu,lb,ru,rb;
        int Exist(const Point &lu, const Point &lb, const Point &ru, const Point &rb);
        int exist;
        double Circumference(const Point &lu, const Point &lb, const Point &ru, const Point &rb);
        double Area(const Point &lu, const Point &lb, const Point &ru, const Point &rb);
    };
}

#endif //JIMP_EXERCISES_SQUARE_H
