#include <algorithm>
#include <iostream>

#include "some_tree.h"

#pragma region private

size_t SomeTree::get_height(Node * node){
    return node != nullptr ? node->height : 0;
}

int SomeTree::get_balance_factor(Node * node){
    return get_height(node->right) - get_height(node->left);
}

void SomeTree::restore_height(Node * node){
    size_t hl = get_height(node->left);
    size_t hr = get_height(node->right);
    node->height = std::max(hl, hr) + 1;
}

Node * SomeTree::right_rotation(Node * root){
    // Шаги
    // 1. Берём левого потомка
    // 2. Корректируем значение суммы в значений в поддеревьях
    // 3. Вешаем с левой стороны корня то что было справа у левого потомка
    // 3. Вешаем с правой стороны левого потомка корень
    // 4. Правим высоты
    
    // Берём потомка
    Node * left_child  = root->left;
    // Корректировка значения суммы
    root->sum_in_left_subtree = left_child->sum_in_right_subtree;
    left_child->sum_in_right_subtree = root->value + root->sum_in_left_subtree + root->sum_in_right_subtree;
    // Поворот
    root->left = left_child->right;
    left_child->right = root;
    restore_height(root);
    restore_height(left_child);
    return left_child;
}

Node * SomeTree::left_rotation(Node * root){
    // Шаги
    // 1. Берём правого потомка 
    // 2. Корректируем значение суммы в значений в поддеревьях
    // 3. Вешаем с правой стороны корня то что было слева у правого потомка
    // 4. Вешаем с левой стороны правого потомка корень
    // 5. Правим высоты

    // Берём потомка
    Node * right_child = root->right;
    // Корректировка значения суммы
    root->sum_in_right_subtree = right_child->sum_in_left_subtree;
    right_child->sum_in_left_subtree = root->value + root->sum_in_left_subtree + root->sum_in_right_subtree;
    // Поворот
    root->right = right_child->left;
    right_child->left = root;
    restore_height(root);
    restore_height(right_child);
    return right_child;
}

Node * SomeTree::balance(Node * node){
    restore_height(node);
	if(get_balance_factor(node) == 2)
	{
		if(get_balance_factor(node->right) < 0 )
			node->right = right_rotation(node->right);
		return left_rotation(node);
	}
	if( get_balance_factor(node) == -2)
	{
		if(get_balance_factor(node->left) > 0)
			node->left = left_rotation(node->left);
		return right_rotation(node);
	}
	return node; // балансировка не нужна
}

void SomeTree::delete_tree(Node * node){
    if(node == nullptr) return;
    delete_tree(node->left);
    delete_tree(node->right);
    std::cout << "Bye bye node with key: " << node->key << std::endl;
    delete node;
}

Node * SomeTree::insert(int value, Node * node){
    if(node == nullptr){
        ++tree_size;
        return new Node(tree_size - 1, value);
    }

    if(tree_size + 1 < node->key){
        node->left = insert(value, node->left);
        node->sum_in_left_subtree += value;
    }
    else{
        node->right = insert(value, node->right);
        node->sum_in_right_subtree += value;
    }
    return balance(node); 
}

void SomeTree::add(size_t i, int y, Node * node){
    if(node->key == i){ 
        node->value += y;
        return;
    }
    
    if(i < node->key){
        add(i, y, node->left);
        node->sum_in_left_subtree += y;
    }
    else{
        add(i, y, node->right);
        node->sum_in_right_subtree += y;
    }
}



Node * SomeTree::find(size_t i, Node * node){
    if(node == nullptr) return nullptr;
    if (node->key == i) return node;
    if (i < node->key){
        return find(i, node->left);
    }
    else{
        return find(i, node->right);
    }
}

std::pair<Node *, Node *> SomeTree::find(size_t i, Node * node, Node * parent){
    if(node == nullptr) return std::pair<Node *, Node *>(nullptr, parent);
    if (node->key == i) return std::pair<Node *, Node *>(node, parent);
    if (i < node->key){
        return find(i, node->left, node);
    }
    else{
        return find(i, node->right, node);
    }
}

#pragma endregion

#pragma region public

void SomeTree::insert(int value){
    head = insert(value, head);
}

void SomeTree::add(size_t i, int y){
    if(i > size() - 1 ) throw std::out_of_range("i is greater than the array size");
    add(i, y, head);
}

int SomeTree::partial_sum(size_t i){
    if(i > size()) throw std::out_of_range("i is greater than the array size");
    if(i == 0) return 0;

    std::pair<Node *, Node *> ith_with_parent = find(i - 1, head, nullptr); // Find ith element with its parent
    
    Node * ith_element = ith_with_parent.first;
    Node * ith_parent = ith_with_parent.second;

    // If ith element is left child or root
    if(ith_parent == nullptr || ith_parent->left == ith_element){
        return ith_element->value + ith_element->sum_in_left_subtree;
    }
    // Else it's right child
    else{
        return ith_element->value + ith_parent->value + ith_parent->sum_in_left_subtree;
    }
}

SomeTree::~SomeTree(){
    delete_tree(head);
}

Node * SomeTree::find(size_t i){
    return find(i, head);
}

#pragma endregion

