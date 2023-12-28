#include <iostream>
#include <vector>

#include "avl_tree.h"


using std::vector;
using std::cout, std::endl;

void member_test(const vector<int> & input){
    AVLTree tree(input);
    for(int item_to_delete : input){
        for(int item: input){
             cout << "\tis " << item << " member of tree? " << tree.member(item) << endl;
        }
        cout << "remove " << item_to_delete << endl;
        tree.remove(item_to_delete);
    }
}

void remove_kth_test(const vector<int> & input){
    for(size_t i = 0; i < input.size(); ++i){
        AVLTree tree(input);
        size_t index_number = i + 1;
        cout << "remove " << index_number << "th two times" << endl;
        tree.remove_kth(index_number);
        tree.remove_kth(index_number);
    }
}

int main(){
    vector<int> test = {10,20,30,40,50};
    //member_test(test);
    remove_kth_test(test);
    return 0;
}