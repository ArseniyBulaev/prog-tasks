#include "binary_tree.h"

Tree::Tree(int * array, size_t array_size){
    Tree * head = nullptr;
    for(size_t i = 0; i < array_size; ++i){
        insert_tree(&head, array[i], nullptr);
    }
    *this = *head;
}

void Tree::insert_tree(Tree ** came_from, int item, Tree * parent){
    if (*came_from == nullptr){
        Tree * new_node = new Tree();
        new_node->item = item;
        new_node->left = new_node->right = nullptr;
        new_node->parent = parent;
        *came_from = new_node;
        return;
    }

    if(item < (*came_from)->item){
        insert_tree(&((*came_from)->left), item, *came_from);
    }
    else{
        insert_tree(&((*came_from)->right), item, *came_from);
    }
    
}