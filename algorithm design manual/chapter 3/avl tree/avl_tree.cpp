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