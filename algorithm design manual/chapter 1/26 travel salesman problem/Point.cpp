#include <cmath>

#include "Point.h"


double Point::calculate_distance(const Point & a, const Point & b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

std::ostream & operator << (std::ostream & out, const Point & point){
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}

bool Point::operator < (const Point & point) const{
    if (this->x != point.x){
       return this->x < point.x;
    }
    else{
        return this->y < point.y;
    }
}

bool Point::operator > (const Point & point) const{
   return point < *this;
}

bool Point::operator == (const Point & point) const {
    return !(point < (*this) || (*this) < point);
}