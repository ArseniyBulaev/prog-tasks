#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

#include "some_tree.h"

using std::cout, std::endl;


void add_test(){
    SomeTree array_tree;
    size_t test_size = 100;
    int min_value = 0;
    int max_value = test_size - 1;
    // First create an instance of an engine.
   std::random_device rnd_device;
   // Specify the engine and distribution.
   std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
   std::uniform_int_distribution<int> dist {min_value, max_value};
    
    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };
    std::vector<int> random_test(test_size);
    generate(begin(random_test), end(random_test), gen);

    for(size_t i = 0; i < random_test.size(); ++i){
        array_tree.insert(random_test[i], i);
    }

    for(size_t i = 0; i <= test_size; ++i){
        size_t indx = gen();
        int value = gen();
        random_test[indx] += value;
        array_tree.add(indx, value);
        Node * node = array_tree.find(indx);
        if(node != nullptr){
            if (node->value != random_test[indx]){
                cout << "node value: " << node->value;
                cout << " vector value: " << random_test[indx] << endl;
            }
        } 
    }

}

int main(){
   //add_test();
   SomeTree array_tree;
   std::vector<int> test = {7, 5, 3, 1, 2, 10, 3 , 3};
   for(size_t i = 0; i < test.size(); ++i){
        array_tree.insert(test[i], i);
   }

   //array_tree.remove(1);
   //array_tree.remove(0);

   for(size_t i = 0; i < test.size(); ++i){
        cout << i << " " << array_tree.partial_sum(i) << endl;
   }

   return 0;
}