#include <iostream>
#include <cmath>

#include "avl_tree.h"

#pragma region public
void AVLTree::insert(int item){
    head = insert(item, head);
}

void AVLTree::remove(int item){
    head = remove(item, head);
}

void AVLTree::traverse(void(*operation)(AVLNode * node)){
    traverse(operation, head);
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

#pragma region  task specific

AVLTree AVLTree::merge(AVLTree t1, AVLTree t2) {
    // каждый элемент из t1 меньше каждого элемента из t2
    AVLNode * t1_max = find_max(t1.head);
    AVLNode * t2_min = find_min(t2.head);
    if(t1_max < t2_min) {
        throw std::invalid_argument("all elements in t1 must be less than all elements in t2");
    }
    AVLTree merged;
    merge(t1.head, t2.head);
    return merged;
}

#pragma endregion task specific

#pragma endregion public

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
    node->left = remove_min(node->left);
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
    return restore_branch_size(balance(node));
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
        return restore_branch_size(balance(min));
    }
    return restore_branch_size(balance(node));
}

void AVLTree::traverse(void(*operation)(AVLNode * node), AVLNode * node){
    if(node == nullptr) return;
    traverse(operation, node->left);
    operation(node);
    traverse(operation, node->right);
}

#pragma region task specific
size_t AVLTree::get_branch_size(AVLNode * node){
    if(node == nullptr) return 0;
    size_t rbs = get_branch_size(node->right);
    size_t lbs = get_branch_size(node->left);
    return rbs + lbs + 1;
}
AVLNode * AVLTree::restore_branch_size(AVLNode * node){
    if(node == nullptr) return node;
    // Востановить левую ветку
    restore_branch_size(node->left);
    // Востановить правую ветку
    restore_branch_size(node->right);
    // Востановить корень
    node->left_branch_size = get_branch_size(node->left);
    node->right_branch_size = get_branch_size(node->right);
    return node;
}

bool AVLTree::is_empty(AVLNode * node){
    return node == nullptr;
}

// AVLNode AVLTree::merge(AVLNode * t1, AVLNode * t2) {
//     if(t1 == nullptr) return t2;
//     if(t2 == nullptr) return t1;
//     // Решение из какого дерева будем брать корень
//     auto choose_head = [](AVLNode * t1, AVLNode * t2){
//         return get_branch_size(t1) > get_branch_size(t2) ? t1 : t2;
//     };
//     AVLNode * new_head = choose_head(t1, t2);
//     // Новый корень
//     AVLNode * t; 
//     if(new_head == t1){
//         AVLNode * t = merge(t1->right, t2);
//         t1->right = t;
//         return restore_branch_size(balance(t1));
//     }
//     else{
//         AVLNode *t = merge(t1, t2->left);
//         t2->left = t;
//         return restore_branch_size(balance(t2));
//     }
// }

 AVLNode * AVLTree::find_max(AVLNode * node){
    return (node->right != nullptr ? find_max(node->right) : node);
 }

#pragma endregion task specific

#pragma endregion private