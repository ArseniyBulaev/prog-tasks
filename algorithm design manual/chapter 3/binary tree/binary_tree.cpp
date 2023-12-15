#include <iostream>

#include "binary_tree.h"

Tree::Tree(int * array, size_t array_size){
    for(size_t i = 0; i < array_size; ++i){
        // Начинаем всегда с head, а родителя у него нет
        // Следоватьльно, можно передавать nullptr при вызове
        insert(&head, array[i], nullptr);
    }
}

Node * Tree::copy(const Node & copy_from, Node * parent){
    Node * new_node = new Node();
    new_node->item = copy_from.item;
    new_node->left = new_node->right = nullptr;
    new_node->parent = parent;

    if (copy_from.left != nullptr){
        new_node->left = copy(*(copy_from.left), new_node);
    }

    if (copy_from.right != nullptr){
        new_node->right = copy(*(copy_from.right), new_node);
    }
    
    return new_node;
}

Tree::Tree(const Tree & copy_from){
    head = copy(*(copy_from.head), nullptr);
}

// O(h), h - tree height
void Tree::insert(Node ** came_from, int item, Node * parent){
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

Node * Tree::search(Node * current, int target) const{
    if(current == nullptr) return nullptr;
    if(current->item == target) return current;
    if(current->item > target) return search(current->left, target);
    else return search(current->right, target);
}

Node * Tree::search(int target) const{
    return search(head, target);
}

Node * Tree::minimum() const {
    Node * min;
    if(head != nullptr) min = head;
    while (min->left != nullptr){
        min = min->left;
    }
    return min;
}

Node * Tree::maximum() const {
    Node * max;
    if(head != nullptr) max = head;
    while (max -> right != nullptr){
        max = max->right;
    }
    return max;
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

void Tree::remove(int item){
    Node * node = search(item);
    // Несуществующая вершина
    if (node == nullptr) return;

    // Удаление вершины без потомков
    if((node->left == nullptr) && (node->right == nullptr)){
        if(node->item < node->parent->item){
            node->parent->left = nullptr;
        }
        else{
            node->parent->right = nullptr;
        }
        // Если удаляемая вершина это корень
        if (head == node) head = nullptr;
        delete node;
        return;
    }

    // Удаление вершины с одним потомком
    // Правая вершина
    if((node->left == nullptr) && !(node->right == nullptr)){
       if((node->right->left == nullptr) && (node->right->right == nullptr)){
            if(node->item < node->parent->item){
                node->parent->left = node->right;
            }
            else{
                node->parent->right = node->right;
            }
        // Если удаляемая вершина это корень
        if (head == node) head = node->right;
        delete node;
        return;
       }    
    }
    // Левая вершина
    if(!(node->left == nullptr) && (node->right == nullptr)){
       if((node->left->left == nullptr) && (node->left->right == nullptr)){
            if(node->item < node->parent->item){
                node->parent->left = node->left;
            }
            else{
                node->parent->right = node->left;
            }
        // Если удаляемая вершина это корень
        if (head == node) head = node->left;
        delete node;
        return;
       }    
    }

    // Вершина с двумя потомками
    // Нужно найти самый левый узел в правом поддереве родительского дерева (дерево, которое удаляется)
    // Поиск нужного узла
    Node * min;
    if(head != nullptr) min = node->right;
    while (min->left != nullptr){
        min = min->left;
    }
    // Подмена найденого и удаляемого узлов
    node->item = min->item;
    if(node->right != min) min->parent->left = nullptr;
    else{
        node->right = min->right;
        min->right->parent = node;
    }
   
    delete min;
}


Tree:: ~Tree(){
    std::cout << "DESTRUCTION:" << std::endl;
    traverse([](Node * p) {
        std::cout << "deleting a node with item: ";
        std::cout<< p->item << std::endl;
        delete p;
    });
}