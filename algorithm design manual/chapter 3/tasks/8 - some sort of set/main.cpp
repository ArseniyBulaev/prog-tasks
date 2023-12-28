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

int main(){
    member_test({1,2,3,4,5});
    return 0;
}