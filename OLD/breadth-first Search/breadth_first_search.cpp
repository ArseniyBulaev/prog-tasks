#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using std::cout, std::endl;
using std::unordered_map;
using std::string;
using std::vector;
using std::queue;


bool breadthFirstSearch(const unordered_map<string, vector<string>> & graph, const string & target, const string & start_vertex) {
    
    queue<string> search_list;
    vector<string> visited;
    search_list.push(start_vertex);

    while (!search_list.empty()){
        string current_vertex = search_list.front();
        if (std::find(visited.begin(), visited.end(), current_vertex) == visited.end()){
           if (current_vertex == target){
            return true;
           }
           else{
            for(const string & vertex: graph.at(current_vertex)){
                search_list.push(vertex);
            }
            visited.push_back(current_vertex);
           }
        }
        search_list.pop();
    }

   return false;
}

void breadthFirstSearchTest(const unordered_map<string, vector<string>> & graph){
    cout << breadthFirstSearch(graph, "thom", "you") << endl;
    cout << breadthFirstSearch(graph, "thomy", "you") << endl;
    cout << breadthFirstSearch(graph, "thom", "claire") << endl;
    cout << breadthFirstSearch(graph, "you", "claire") << endl;
    cout << breadthFirstSearch(graph, "claire", "you") << endl;
}


int main(){

    unordered_map<string, vector<string>> graph = {
        {"you", {"alice", "bob", "claire"}},
        {"alice", {"peggy"}},
        {"bob", {"peggy", "anuj"}},
        {"claire", {"thom", "jonny"}},
        {"anuj", {}},
        {"thom", {}},
        {"jonny", {}},
        {"peggy", {}}
    };


    breadthFirstSearchTest(graph);

    return 0;
}
