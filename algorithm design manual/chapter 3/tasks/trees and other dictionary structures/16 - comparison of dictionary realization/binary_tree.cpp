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

void Tree::remove_if_leaf(Node * to_delete){
    if(to_delete != head){
        Node * parent = to_delete->parent;
        if(to_delete->item >= parent->item){
            parent->right = nullptr;
        }
        else{
            parent->left = nullptr;
        }
    }
    else{
        head = nullptr;
    }
}

void Tree::remove_if_one_child(Node * to_delete){
  Node * child = to_delete->left != nullptr? to_delete->left : to_delete->right;
  if(to_delete != head){
        Node * parent = to_delete->parent;
        if(to_delete->item >= parent->item){
            parent->right = child;
        }
        else{
            parent->left = child;
        }
        child->parent = parent;
    }
    else{
        head = child;
        child->parent = nullptr;
    }
}

void Tree::remove_if_two_children(Node * to_delete){
    // Самый левый узел в правом дереве родительского поддерева
    Node * most_left = to_delete->right;
    while (most_left->left != nullptr){
        most_left = most_left->left;
    }
    // Нужно удалить предка у самого левого
    if(most_left != to_delete->right) most_left->parent->left=nullptr;
    // Самый правый узел в самом левом узле
    Node * most_right = most_left;
    while (most_right->right != nullptr){
        most_right = most_right->right;
    }

    // Переподвешиваем потомков удаляемого узла
    most_left->left = to_delete->left;
    to_delete->left->parent = most_left;
    // Если самый правый в самом левом не равен правому в узле, который удаляем
    if(most_right != to_delete->right)
        most_right->right = to_delete->right;
    to_delete->right->parent = most_right;

    // Связь с исходным родителем
    if(to_delete != head){
        Node * parent = to_delete->parent;
        if(to_delete->item >= parent->item){
            parent->right = most_left;
        }
        else{
            parent->left = most_left;
        }
        most_left->parent = parent;
    }
    else{
        head = most_left;
        most_left->parent = nullptr;
    }

}

void Tree::remove(int item){
   // Чтобы удалить ноду её нужно сначала найти
   Node * to_delete = search(item);
   // Если такой ноды нет, то ничего не нужно делать
   if (to_delete == nullptr) return;
   // Если нода является листом
   if(to_delete->left == nullptr && to_delete->right == nullptr){ 
        remove_if_leaf(to_delete);
   }
   // Если нода имеет двух потомков
   else if (to_delete->left != nullptr && to_delete->right != nullptr){
        remove_if_two_children(to_delete);
   }
   // Если у ноды один потомок
   else{
        remove_if_one_child(to_delete);
   }
   // Почистить ресурсы
   delete to_delete;
}


Tree:: ~Tree(){
    std::cout << "DESTRUCTION:" << std::endl;
    traverse([](Node * p) {
        std::cout << "deleting a node with item: ";
        std::cout<< p->item << std::endl;
        delete p;
    });
}