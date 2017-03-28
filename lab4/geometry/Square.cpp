//
// Created by Hela on 21.03.2017.
//

//
// Created by kolahele on 21.03.17.
#include "Square.h"
#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

namespace geometry {
    Square::Square( Point lu,  Point lb,  Point ru,  Point rb) {
        this -> lu = lu;
        this ->lb = lb;
        this ->ru = ru;
        this ->rb = rb;
    }
    double Square::Circumference() {
        double circumference;
        double edge;
        edge=this->lu.Distance(this->lb);
        circumference =  edge * 4;

        return circumference;
    }

    double Square::Area() {
        double area;
        double edge;
        edge=this->lu.Distance(this->lb);
        area =  edge * edge;
        return area;
    }
}
