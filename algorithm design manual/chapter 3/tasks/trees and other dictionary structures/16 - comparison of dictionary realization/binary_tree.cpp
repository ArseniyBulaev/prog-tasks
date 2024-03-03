#include <iostream>
#include <string>

#include "binary_tree.h"



// O(h), h - tree height
void Tree::insert(Node ** came_from, const std::string & item, Node * parent){
    if (*came_from == nullptr){
        Node * new_node = new Node();
        new_node->item = item;
        new_node->left = new_node->right = nullptr;
        new_node->parent = parent;
        *came_from = new_node;
        return;
    }

    if(item < (*came_from)->item){
        insert(&((*came_from)->left), item, *came_from);
    }
    else{
        insert(&((*came_from)->right), item, *came_from);
    }
    
}

void Tree::insert(const std::string & item){
    insert(&head, item, nullptr);
}

Node * Tree::search(Node * current, const std::string & target) const{
    if(current == nullptr) return nullptr;
    if(current->item == target) return current;
    if(current->item > target) return search(current->left, target);
    else return search(current->right, target);
}

bool Tree::search(const std::string & target) const{
    Node * search_result = search(head, target);
    if (search_result == nullptr){
        return false;
    }
    else{
        return search_result->item == target;
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
    // std::cout << "DESTRUCTION:" << std::endl;
    traverse([](Node * p) {
        // std::cout << "deleting a node with item: ";
        // std::cout<< p->item << std::endl;
        delete p;
    });
}