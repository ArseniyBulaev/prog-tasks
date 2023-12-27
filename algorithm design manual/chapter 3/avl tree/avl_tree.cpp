#include <iostream>
#include <cmath>

#include "avl_tree.h"

#pragma region public
void AVLTree::insert(int item){
    head = insert(item, head);
}

void AVLTree::remove(int item){
    remove(item, head);
}

AVLTree::AVLTree(const std::vector<int> & items){
    for(int item : items){
        insert(item);
    }
}

AVLTree::AVLTree(const AVLTree & tree){
    head = create_from(tree.head);
}

AVLTree::~AVLTree(){
  std::cout << "Destructor (sounds of death...):" << std::endl;
  delete_tree(head);
}

#pragma endregion

#pragma region private

size_t AVLTree::get_height(AVLNode * node){
    return node != nullptr ? node->height : 0;
}

int AVLTree::get_balance_factor(AVLNode * node){
    return get_height(node->right) - get_height(node->left);
}

void AVLTree::restore_height(AVLNode * node){
    size_t hl = get_height(node->left);
    size_t hr = get_height(node->right);
    node->height = std::max(hl, hr) + 1;
}

AVLNode * AVLTree::right_rotation(AVLNode * root){
    // Шаги
    // 1. Берём левого потомка
    // 2. Вешаем с левой стороны корня то что было справа у левого потомка
    // 3. Вешаем с правой стороны левого потомка корень
    // 4. Правим высоты
    AVLNode * left_child  = root->left;
    root->left = left_child->right;
    left_child->right = root;
    restore_height(root);
    restore_height(left_child);
    return left_child;
}

AVLNode * AVLTree::left_rotation(AVLNode * root){
    // Шаги
    // 1. Берём правого потомка 
    // 2. Вешаем с правой стороны корня то что было слева у правого потомка
    // 3. Вешаем с левой стороны правого потомка корень
    // 4. Правим высоты
    AVLNode * right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;
    restore_height(root);
    restore_height(right_child);
    return right_child;
}

AVLNode * AVLTree::balance(AVLNode * node){
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

void AVLTree::delete_tree(AVLNode * node){
    if(node == nullptr) return;
    delete_tree(node->left);
    delete_tree(node->right);
    std::cout << "Bye bye node with value: " << node->item << std::endl;
    delete node;
}

AVLNode * AVLTree::create_from(AVLNode * original){
    AVLNode * copy = nullptr;
    if(original != nullptr){
        // Копируем содержимое
        copy = new AVLNode(original->item);
        // Копируем высоту
        copy->height = original->height;
        // Копируем левую ветку
        copy->left = create_from(original->left);
        // Копируем правую ветку
        copy->right = create_from(original->right);
    } 
    return copy;
}

AVLNode * AVLTree::find_min(AVLNode * node){
    return (node->left != nullptr ? find_min(node->left) : node);
}

AVLNode * AVLTree::remove_min(AVLNode * node){
    if(node->left == nullptr){
        return node->right;
    }
    node->left = (node->left);
    return balance(node);
}

AVLNode * AVLTree::insert(int item, AVLNode * node){
    if(node == nullptr) return new AVLNode(item);
    if(node->item == item) return node;
    if(item < node->item){
        node->left = insert(item, node->left);
    }
    else{
        node->right = insert(item, node->right);
    }
    return balance(node);
}

AVLNode * AVLTree::remove(int item, AVLNode * node){
    if(node == nullptr) return node;
    if(item < node->item){
        node->left = remove(item, node->left);
    }
    else if(item > node->item){
        node->right = remove(item, node->right);
    }
    // Элемент для удаления найден
    else{
        AVLNode * left_child = node->left;
        AVLNode * right_child = node->right;
        delete node;
        if(right_child == nullptr) return left_child;
        AVLNode * min = find_min(right_child);
        min->right = remove_min(right_child);
        min->left = left_child;
        return balance(min);
    }
    return balance(node);
}

#pragma endregion