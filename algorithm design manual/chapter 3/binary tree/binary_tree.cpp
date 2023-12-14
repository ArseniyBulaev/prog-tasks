#include "binary_tree.h"

Tree::Tree(int * array, size_t array_size){
    this->item = array[0];
    Tree * head = this;
    for(size_t i = 1; i < array_size; ++i){
        insert_tree(&head, array[i], nullptr);
    }
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

void Tree::traverse(void (*operation) (Tree * node), Tree * node_p){
    if (node_p != nullptr){
        traverse(operation, node_p->left);
        operation(node_p);
        traverse(operation, node_p->right);
    }
}

void Tree::traverse(void (*operation) (Tree * node)){
    traverse(operation, this);
}

const Tree * Tree::get_parent() const{
    return this->parent;
}

int Tree::get_item() const{
    return this->item;
}