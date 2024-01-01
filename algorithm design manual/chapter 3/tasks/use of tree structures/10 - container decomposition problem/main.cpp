#include "tree.h"

#include <vector>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::cout, std::endl;

size_t container_decomposition_problem(const std::vector<double> & weights){
    Tree containers;
    for(double weight: weights){
        containers.insert(weight);
    }
    return containers.size;
}

void print(const std::vector<double> & vec){
    cout << "{";
    for (size_t i = 0; i < vec.size(); ++i){
       cout << vec[i];
       if(i < vec.size() - 1) cout << " , ";
    }
    cout << "}";
}


int main(){
    std::unordered_map<std::vector<double>, size_t> test_cases = {
        {{0.8, 0.7, 0.6}, 3}
    };

    

    for(const auto & test_case : test_cases){
        print(test_case.first);
        cout << " " << (container_decomposition_problem(test_case.first) == test_case.second) << endl;
    }

    return 0;
}