#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <algorithm>

#include "Point.h"
#include "nearest neighbor.hpp"

using std::vector, std::set;
using std::cout, std::endl;

double calculate_route_distance(const vector<Point> & route){
    double route_distance = 0;
    for (size_t i = 0; i < route.size() - 1; ++i){
        route_distance += Point::calculate_distance(route[i], route[i + 1]);
    }
    return route_distance;
}

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
    cout << "route_distance: " << calculate_route_distance(route);
}


int main(){
    test();
    return 0;
}