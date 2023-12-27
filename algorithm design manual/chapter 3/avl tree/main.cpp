#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

#include "avl_tree.h"

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
   size_t number_of_random_values = 5;
   int min_value = 1;
   int max_value = 100;
   std::vector<int> random_numbers = generate_random_vector(number_of_random_values, min_value, max_value);
   size_t random_indx = generate_random_value(0, random_numbers.size());
   int random_item_from_numbers = random_numbers[random_indx]; 
   AVLTree tree(random_numbers);
   tree.remove(random_item_from_numbers);
   return 0;
}