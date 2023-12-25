#include "avl_tree.h"

void AVLTree::insert(int item){
     insert(head, item);   
}

void AVLTree::insert(AVLNode * current, int item){
    // Место для вставки найдено
    if (current == nullptr){
        current = new AVLNode(item);
        return;
    }
    // Одинаковые элементы не всталяем
    if (current->item == item) return;
    // Ищем место для вставки
    if (item < current->item){
        insert(current->left, item);
    }
    else{
        insert(current->right, item);
    }
}

size_t AVLTree::get_height(AVLNode * node){
    return node != nullptr ? node->height : 0;
}

int AVLTree::calc_balance_factor(AVLNode * node){
    AVLNode * left_node = node->left;
    AVLNode * right_node = node->right;
    return get_height(left_node) - get_height(right_node);
}

void AVLTree::fix_height(AVLNode * node){
    size_t left_height = get_height(node->left);
    size_t right_height = get_height(node->right);
    node->height = left_height > right_height ? left_height : right_height;
}

AVLNode * AVLTree::rotate_left(AVLNode * x){
   AVLNode * y = x->left;
   x->left = y->right;
   y->right = x;
   fix_height(x);
   fix_height(y);
   return y;
}

AVLNode * AVLTree::rotate_right(AVLNode * x){
   AVLNode * y = x->right;
   x->right = y->left;
   y->left = x;
   fix_height(x);
   fix_height(y);
   return y;
}