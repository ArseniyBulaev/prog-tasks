#include <algorithm>
#include <iostream>

#include "some_tree.h"


#pragma region public

// -1 Значит, что ключ не задан
void SomeTree::insert(int value, int key){
    head = insert(key, value, head);
}

void SomeTree::add(int key, int y){
    add(key, y, head);
}

int SomeTree::partial_sum(int key){
    return partial_sum(key, head);
}

void SomeTree::remove(int key){
    head = remove(key, head);
    --tree_size;
}

SomeTree::~SomeTree(){
    delete_tree(head);
}

Node * SomeTree::find(size_t i){
    return find(i, head);
}

#pragma endregion


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

Node * SomeTree::insert(int key, int value, Node * node){
    if(node == nullptr){
        ++tree_size;
        return new Node(key, value);
    }

    if(key < node->key){
        node->left = insert(key, value, node->left);
        node->sum_in_left_subtree += value;
    }
    else{
        node->right = insert(key, value, node->right);
        node->sum_in_right_subtree += value;
    }
    return balance(node); 
}

void SomeTree::add(int key, int y, Node * node){
    
    if(node == nullptr) throw std::invalid_argument("there isn't such key");

    if(node->key == key){ 
        node->value += y;
        return;
    }
    
    if(key < node->key){
        add(key, y, node->left);
        node->sum_in_left_subtree += y;
    }
    else{
        add(key, y, node->right);
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
    if(node == nullptr) return 0;
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

Node * SomeTree::find_min(Node * node){
    return (node->left != nullptr ? find_min(node->left) : node);
}

Node * SomeTree::remove_min(Node * node){
    if(node->left == nullptr){
        return node->right;
    }
    node->left = remove_min(node->left);
    return balance(node);
}

void SomeTree::restore_sum_in_subtrees(Node * node){
    if(node != nullptr){
        node->sum_in_left_subtree = node->left != nullptr ? node->left->value + node->left->sum_in_left_subtree + node->left->sum_in_right_subtree : 0;
        node->sum_in_right_subtree = node->right != nullptr ? node->right->value + node->right->sum_in_left_subtree + node->right->sum_in_right_subtree : 0;
    }
}

Node * SomeTree::remove(int key, Node * node){
    if(node == nullptr) throw std::invalid_argument("there isn't such key");
    if(key < node->key){
        node->left = remove(key, node->left);
        restore_sum_in_subtrees(node);
    }
    else if(key > node->key){
        node->right = remove(key, node->right);
        restore_sum_in_subtrees(node);
    }
    // Элемент для удаления найден
    else{
        Node * left_child = node->left;
        Node * right_child = node->right;
        int origin_sum_in_left_subtree = node->sum_in_left_subtree;
        delete node;
        if(right_child == nullptr) return left_child;
        Node * min = find_min(right_child);
        min->right = remove_min(right_child);
        min->left = left_child;
        min->sum_in_left_subtree = origin_sum_in_left_subtree;
        return balance(min);
    }
    return balance(node);
}

#pragma endregion
