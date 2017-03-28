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
        Square( Point lu,  Point lb,  Point ru,  Point rb);
        double Circumference();
        double Area();
    private:
        Point lu,lb,ru,rb;





    };
}

#endif //JIMP_EXERCISES_SQUARE_H
