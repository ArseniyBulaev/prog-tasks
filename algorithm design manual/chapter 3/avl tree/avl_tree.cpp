#include <iostream>
#include <cmath>

#include "avl_tree.h"

size_t AVLTree::get_height(AVLNode * node){
    return node != nullptr ? node->height : 0;
}
