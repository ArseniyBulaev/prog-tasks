#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<limits>
#include<algorithm>

using namespace std;

string find_cheapest_vertex(const unordered_map<string, int>& costs, const vector<string>& visited) {
    string cheapest_vertex = "";
    int cheapest_vertex_value = std::numeric_limits<int>::max();
    for (const std::pair<string, int>& n : costs) {
        const string& vertex = n.first;
        int cost = n.second;
        if (std::find(visited.begin(), visited.end(), vertex) == visited.end()) {
            if (cost < cheapest_vertex_value) {
                cheapest_vertex = vertex;
                cheapest_vertex_value = cost;
            }
        }
    }
    return cheapest_vertex;
}

void dijkstra_algorithm(const unordered_map<string, unordered_map<string, int>>& graph, const string& start, const string& target) {

    if (start == target) {
        cout << "cost: 0" << endl << "path: " << start << endl;
    }
    unordered_map<string, int> costs = graph.at(start);
    unordered_map<string, string> parents;
    for (const std::pair<string, int>& n : graph.at(start)) {
        const string& vertex = n.first;
        parents[vertex] = start;
    }
    vector<string> visited;

    string cheapest_vertex = find_cheapest_vertex(costs, visited);

    while (cheapest_vertex != "") {
        int cost = costs[cheapest_vertex];
        for (const std::pair<string, int>& n : graph.at(cheapest_vertex)) {
            const string& neighbor_vertex = n.first;
            int neighbor_cost = n.second;

            if (costs.find(neighbor_vertex) == costs.end()) {
                costs[neighbor_vertex] = cost + neighbor_cost;
                parents[neighbor_vertex] = cheapest_vertex;
            }
            else {
                if (costs[neighbor_vertex] > cost + neighbor_cost) {
                    costs[neighbor_vertex] = cost + neighbor_cost;
                    parents[neighbor_vertex] = cheapest_vertex;
                }
            }
        }

        visited.push_back(cheapest_vertex);
        cheapest_vertex = find_cheapest_vertex(costs, visited);
    }

    if (costs.find(target) != costs.end()) {
        cout << "coast: " << costs[target] << endl << "path: ";
        string nearest_parent = target;
        do {
            cout << nearest_parent << "<-";
            nearest_parent = parents[nearest_parent];
        } while (nearest_parent != start);
        cout << nearest_parent;
    }
    else {
        cout << "path doesn't exist" << endl;
    }

    cout << endl;
}

int main() {

    unordered_map<string, unordered_map<string, int>> test = {
        {"start", {{"a", 5}, {"b", 2}}},
        {"a", {{"c", 2}, {"d", 4}}},
        {"b", {{"c", 7}, {"a", 8}}},
        {"c", {{"fin", 1}}},
        {"d", {{"c",6}, {"fin", 3}}},
        {"fin", {}}
    };

    dijkstra_algorithm(test, "start", "fin");
    dijkstra_algorithm(test, "start", "d");
    dijkstra_algorithm(test, "start", "c");


    return 0;
}