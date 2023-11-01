#include <map>
#include <vector>
#include <limits>
#include <algorithm>
#include <set>

#include "closet pair.hpp"

using std::map, std::vector, std::set;


vector<Point> closet_pair(const set<Point> & points){
    vector<Point> route;
    map<Point, set<Point>> chains;
    for (const Point & p: points){
        chains[p] = {};
    }

    for (size_t i = 0; i < points.size() - 1; ++i){
        double d = std::numeric_limits<double>::infinity();
        Point s_m, t_m;
        for (const Point & s : points){
            for (const Point & t : points){
                if(s != t && std::find(chains[s].begin(), chains[s].end(), t) == chains[s].end()){
                    double s_to_t_d = Point::calculate_distance(s, t);
                    if (s_to_t_d < d){
                        s_m = s;
                        t_m = t;
                        d = s_to_t_d;
                    }
                }
            }
        }

        for(const Point & p: chains[s_m]){
            chains[p].push_back(t_m);
        }
        chains[s_m].push_back(t_m);
        for(const Point & p: chains[t_m]){
            chains[p].push_back(s_m);
        }
        chains[t_m].push_back(s_m);
        route.push_back(s_m);
        route.push_back(t_m);
    }
    return route;
}

