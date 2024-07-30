#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <algorithm>

#include "Point.h"
#include "nearest neighbor.hpp"
#include "closet pair.hpp"

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

    vector<Point> closet_pair_route = closet_pair(points);
    vector<Point> nearest_neighbor_route = nearest_neighbor(points);

    cout << "closet_pair_route_distance: " << calculate_route_distance(closet_pair_route) << endl;
    cout << "nearest_neighbor_distance: " << calculate_route_distance(nearest_neighbor_route);
}


int main(){
    test();
    return 0;
}