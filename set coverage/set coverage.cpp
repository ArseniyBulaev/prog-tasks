#include<iostream>
#include<set>
#include<unordered_map>
#include<string>
#include<algorithm>

using std::set, std::string, std::unordered_map;
using std::cout, std::endl;

set<string> state_station_coverage(set<string> states_to_cover, const unordered_map<string, set<string>> & stations){
    set<string> necessary_stations;
    while (!states_to_cover.empty()){
        string best_station;
        set<string> best_covered;
        for(const std::pair<string, set<string>> & p : stations){
            const string & station = p.first;
            const set<string> & covered_states = p.second;
            set<string> covered;
            std::set_intersection(states_to_cover.begin(), states_to_cover.end(),
             covered_states.begin(), covered_states.end(), std::inserter(covered, covered.begin()));
            if(covered.size() > best_covered.size()){
                best_station = station;
                best_covered = covered;
            }
        }
        set<string> remaining_states;
         std::set_difference(states_to_cover.begin(), states_to_cover.end(),
          best_covered.begin(), best_covered.end(), std::inserter(remaining_states, remaining_states.begin()));
        states_to_cover = remaining_states;
        necessary_stations.insert(best_station);
    }
    return necessary_stations;
}

int main (){

    set<string> states = {"mt", "wa", "or", "id", "nv", "ut", "ca", "az"};
    unordered_map<string, set<string>> stations = {
        {"kone", {"id", "nv", "ut"}},
        {"ktwo", {"id", "wa", "mt"}},
        {"kthree", {"or", "nv", "ca"}},
        {"kfour", {"nv", "ut"}},
        {"kfive", {"ca", "az"}}
    };


    set<string> needed_stations = state_station_coverage(states, stations);

    for(const string & station: needed_stations) cout << station << " ";
    cout << endl;

    return 0;
}