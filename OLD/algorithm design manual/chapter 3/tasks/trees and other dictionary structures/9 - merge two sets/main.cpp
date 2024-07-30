#include "avl_tree.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

using std::vector;

std::vector<int> generate_random_vector(size_t size, int min_value, int max_value){
   // First create an instance of an engine.
   std::random_device rnd_device;
   // Specify the engine and distribution.
   std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
   std::uniform_int_distribution<int> dist {min_value, max_value};
    
    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };
    std::vector<int> vec(size);
    generate(begin(vec), end(vec), gen);
    return vec;
}

void merge_test(){
    std::vector<int> random_input_1 = generate_random_vector(15, 0, 15);
    std::vector<int> random_input_2 = generate_random_vector(10, 16, 25);
    AVLTree t1(random_input_1);
    AVLTree t2(random_input_2);
    AVLTree merged = AVLTree::merge(t1, t2);
}

int main(){
    merge_test();
    return 0;
}