#include <iostream>

#include "binary_tree.h"

Tree::Tree(int * array, size_t array_size){
    for(size_t i = 0; i < array_size; ++i){
        // Начинаем всегда с head, а родителя у него нет
        // Следоватьльно, можно передавать nullptr при вызове
        insert_tree(&head, array[i], nullptr);
    }
}

// O(h), h - tree height
void Tree::insert_tree(Node ** came_from, int item, Node * parent){
    if (*came_from == nullptr){
        Node * new_node = new Node();
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

// O(h), h - tree height
void Tree::traverse(void (*operation) (Node * node), Node * node_p){
    if (node_p != nullptr){
        traverse(operation, node_p->left);
        traverse(operation, node_p->right);
        operation(node_p);
    }
}

void Tree::traverse(void (*operation) (Node * node)){
    traverse(operation, head);
}


Tree:: ~Tree(){
    std::cout << "DESTRUCTION:" << std::endl;
    traverse([](Node * p) {
        std::cout << "deleting a node with item: ";
        std::cout<< p->item << std::endl;
        delete p;
    });
}