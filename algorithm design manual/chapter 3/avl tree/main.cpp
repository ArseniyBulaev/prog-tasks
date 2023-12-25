#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

#include "avl_tree.h"

std::vector<int> generate_random_vector(size_t size){
    using namespace std;
     // First create an instance of an engine.
    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    uniform_int_distribution<int> dist {1, 100};
    
    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };

    vector<int> vec(size);
    generate(begin(vec), end(vec), gen);
    return vec;
}

void insert_test(const std::vector<int> & random_vector, AVLTree & tree){
    for(int random_number: random_vector){
        tree.insert(random_number);
    }
}

int main(){
    AVLTree tree;
    return 0;
}