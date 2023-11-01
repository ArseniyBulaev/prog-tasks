#include <iostream>

struct Point{
    int x;
    int y;
    Point(int x, int y): x(x), y(y) {}
    bool operator < (const Point & point) const;
    bool operator > (const Point & point) const;
    bool operator == (const Point & point) const;
    static double calculate_distance(const Point &, const Point &);
    friend std::ostream & operator << (std::ostream & out, const Point & point);
};