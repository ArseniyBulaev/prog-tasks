#include <iostream>

#include "avl_tree.h"

AVLTree::AVLTree(const std::vector<int> & values){
    for(int value: values){
        insert(value);
    }
}

void AVLTree::delete_tree(AVLNode * node){
    if(node == nullptr) return;
    delete_tree(node->left);
    delete_tree(node->right);
    std::cout << "Bye bye node with value: " << node->item << std::endl;
    delete node;
}

AVLTree::~AVLTree(){
  std::cout << "Destructor (sounds of death...):" << std::endl;
  delete_tree(head);
}

void AVLTree::insert(int item){
     head = insert(head, item);   
}

AVLNode * AVLTree::insert(AVLNode * current, int item){
    // Место для вставки найдено
    if (current == nullptr){
        return new AVLNode(item);
    }
    // Одинаковые элементы не всталяем
    if (current->item == item) return current;
    // Ищем место для вставки
    if (item < current->item){
        current->left = insert(current->left, item);
        current->left->parent = current;
    }
    else{
        current->right = insert(current->right, item);
        current->right->parent = current;
    }
    // Балансировка
    return balance(current);
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

AVLNode * AVLTree::balance(AVLNode * x){
    fix_height(x);
    if(x->height == 2){
        // Если зашли сюда значит выполняется RL-поворот
        // Иначе RR-поворот
        if(calc_balance_factor(x->right) < 0)
			x->right = rotate_right(x->right);
		return rotate_left(x);
    }
    if(x->height == -2){
        // Если зашли сюда значит выполняется LR-поворот
        // Иначе LL-поворот
        if(calc_balance_factor(x->left) > 0)
			x->left = rotate_left(x->left);
		return rotate_right(x);
    }
    return x; // Балансировка не нужна
}