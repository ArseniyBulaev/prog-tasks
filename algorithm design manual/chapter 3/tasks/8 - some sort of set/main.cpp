#include <iostream>
#include <vector>

#include "avl_tree.h"


using std::vector;

int main(){
    AVLTree tree({1,2,3,4,5});
    tree.remove(2);
    return 0;
}