#include "avl_tree.h"
#include <vector>

using std::vector;

void merge_test(){
    AVLTree t1({1,2,3});
    AVLTree t2({4,5,6});
    AVLTree::merge(t1, t2);
}

int main(){
    merge_test();
    return 0;
}