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

// Алгоритм
// Ишем ноду с заданным ключём, походу собирая значения в нодах,
// у которых значение ключа меньше заданного 
int SomeTree::partial_sum(size_t i, Node * node){
    if(node == nullptr) throw std::logic_error("node can't be nullptr");
    // Когда нашли заданную ноду нужно добавить сумму значений в левом поддереве,
    // так как слева висят все ноды с ключами меньше заданного или их там вообще нет
    if (node->key == i) return node->value + node->sum_in_left_subtree; 
    int part_sum = 0;
    // Если ключ текущей ноды в ходе поиска меньше заданного,
    // Нужно учесть текущую ноду и её левое поддерево (потому что там ключи меньше заданного)
    if(node->key < i){
        part_sum += node->value + node->sum_in_left_subtree;
    }
    if (i < node->key){
        part_sum += partial_sum(i, node->left);
    }
    else{
        part_sum += partial_sum(i, node->right);
    }
    
    return part_sum;
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
    return partial_sum(i - 1 , head);
}

SomeTree::~SomeTree(){
    delete_tree(head);
}

Node * SomeTree::find(size_t i){
    return find(i, head);
}

#pragma endregion

