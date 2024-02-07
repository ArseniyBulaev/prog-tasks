#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

#include "some_tree.h"

using std::cout, std::endl;

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

int generate_random_value(int min_value, int max_value){
    // First create an instance of an engine.
   std::random_device rnd_device;
   // Specify the engine and distribution.
   std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
   std::uniform_int_distribution<int> dist {min_value, max_value};
    
    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };
    return gen();
}


int main(){
   SomeTree array_tree;
   std::vector<int> test = {10, 12, 3, 5, 1};
   for(int value : test){
        array_tree.insert(value);
   }
   array_tree.add(0, 4);
   return 0;
}