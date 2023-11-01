#include <map>
#include <vector>
#include <limits>

#include "closet pair.hpp"

using std::map, std::vector;

bool are_connected(const Point & s, const Point & t, const map<Point, std::set<Point>> & point_chains){
    if (point_chains.find(t) == point_chains.end()) return false;
    for (const Point & p: point_chains.at(t)){
        if (p == s){
            return true;
        }
        return are_connected(s, p, point_chains);
    }
}

vector<Point> closet_pair(const std::set<Point> & points){
   map<Point, std::set<Point>> point_chains;
    vector<Point> route;
    for (size_t i = 0; i < points.size() - 1; ++i){
        double d = std::numeric_limits<double>::infinity();
        Point s_m, t_m;
        for(const Point & s : points){
            for(const Point & t : points){
                if (t != s && !are_connected(s, t, point_chains)){
                    double s_to_t_dist = Point::calculate_distance(s, t);
                    if (s_to_t_dist <= d){
                        s_m = s;
                        t_m = t;
                        d = s_to_t_dist;
                    } 
                }
            }
        }
        // Cоединяем (s_m, t_m) ребром
        point_chains[s_m].insert(t_m);
        point_chains[t_m].insert(s_m);
        route.push_back(s_m);
        route.push_back(t_m);
    }
    // Cоединяем две конечные точки ребром
    Point start_point = route.front();
    Point end_point = route.front();
    point_chains[start_point].insert(end_point);
    point_chains[end_point].insert(start_point);
    route.push_back(start_point);

    return route;
}

