#include <map>
#include <vector>
#include <limits>
#include <algorithm>
#include <set>

#include "closet pair.hpp"

using std::map, std::vector, std::set;


vector<Point> closet_pair(const set<Point> & points){
    vector<Point> route;
    vector<set<Point>> chains;
    
    for (size_t i = 0; i < points.size() - 1; ++i){
        double d = std::numeric_limits<double>::infinity();
        Point s_m, t_m;
        for (const Point & s : points){
            for (const Point & t : points){
                if(s != t){
                    bool both_points_in_the_same_chain;
                    for(const set<Point> & chain: chains){
                        both_points_in_the_same_chain =
                         std::find(chain.begin(), chain.end(), t) != chain.end() &
                         std::find(chain.begin(), chain.end(), s) != chain.end();
                    }

                    if (!both_points_in_the_same_chain){
                            double s_to_t_d = Point::calculate_distance(s, t);
                            if (s_to_t_d < d){
                                s_m = s;
                                t_m = t;
                                d = s_to_t_d;
                            }
                    }
                }
            }
        }

        set<Point> sm_chain, tm_chain, new_chain;

        for(set<Point> & chain: chains){
           auto sm_chain_it = chain.find(s_m);
           auto tm_chain_it = chain.find(t_m);
           if (sm_chain_it != chain.end()) sm_chain = chain;
           if (tm_chain_it != chain.end()) tm_chain = chain;
        }

        if(!sm_chain.empty()){
            chains.erase(std::remove(chains.begin(), chains.end(), sm_chain), chains.end());
            for(const Point & p : sm_chain){
                new_chain.insert(p);
            }
        }
        else{
            new_chain.insert(s_m);
        }

        if(!tm_chain.empty()){
            chains.erase(std::remove(chains.begin(), chains.end(), tm_chain), chains.end());
            for(const Point & p : tm_chain){
                new_chain.insert(p);
            }
        }
        else{
            new_chain.insert(t_m);
        }

        chains.push_back(new_chain);
      
        route.push_back(s_m);
        route.push_back(t_m);
    }
    return route;
}

