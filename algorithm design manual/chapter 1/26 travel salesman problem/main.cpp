#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <algorithm>

#include "Point.h"
#include "nearest_neighbor.h"

using std::vector, std::set;
using std::cout, std::endl;


void test(){
    set<Point> points {
            Point(0, 0), Point(1, 0), Point(-1, 0),
            Point(3, 0), Point(-5, 0), Point(11, 0),
            Point(-21, 0)
        };

    vector<Point> route = nearest_neighbor(points);

    for(const Point & p: route){
        cout << p << " ";
    }
    cout << endl;
}


int main(){
    test();
    return 0;
}