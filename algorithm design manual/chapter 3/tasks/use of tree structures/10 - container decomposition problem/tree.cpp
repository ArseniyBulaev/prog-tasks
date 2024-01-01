#include <iostream>
#include <cmath>

#include "tree.h"

#pragma region container

bool Container::push(double weight){
    if(available_space - weight >= 0){
        available_space -= weight;
        return true;
    }
    return false;
}

#pragma endregion container


#pragma region public

Tree::~Tree(){
  std::cout << "Destructor (sounds of death...):" << std::endl;
  delete_tree(head);
}

#pragma endregion public

#pragma region private

size_t Tree::get_height(Container * node){
    return node != nullptr ? node->height : 0;
}

int Tree::get_balance_factor(Container * node){
    return get_height(node->right) - get_height(node->left);
}

void Tree::restore_height(Container * node){
    size_t hl = get_height(node->left);
    size_t hr = get_height(node->right);
    node->height = std::max(hl, hr) + 1;
}

Container * Tree::right_rotation(Container * root){
    // Шаги
    // 1. Берём левого потомка
    // 2. Вешаем с левой стороны корня то что было справа у левого потомка
    // 3. Вешаем с правой стороны левого потомка корень
    // 4. Правим высоты
    Container * left_child  = root->left;
    root->left = left_child->right;
    left_child->right = root;
    restore_height(root);
    restore_height(left_child);
    return left_child;
}

Container * Tree::left_rotation(Container * root){
    // Шаги
    // 1. Берём правого потомка 
    // 2. Вешаем с правой стороны корня то что было слева у правого потомка
    // 3. Вешаем с левой стороны правого потомка корень
    // 4. Правим высоты
    Container * right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;
    restore_height(root);
    restore_height(right_child);
    return right_child;
}

Container * Tree::balance(Container * node){
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

void Tree::delete_tree(Container * node){
    if(node == nullptr) return;
    delete_tree(node->left);
    delete_tree(node->right);
    std::cout << "Bye bye node with value: " << node->available_space << std::endl;
    delete node;
}


Container * Tree::find_min(Container * node){
    return (node->left != nullptr ? find_min(node->left) : node);
}

Container * Tree::remove_min(Container * node){
    if(node->left == nullptr){
        return node->right;
    }
    node->left = remove_min(node->left);
    return balance(node);
}


Container * Tree::remove(double weight, Container * node){
    if(node == nullptr) return node;
    if(weight < node->available_space){
        node->left = remove(weight, node->left);
    }
    else if(weight > node->available_space){
        node->right = remove(weight, node->right);
    }
    // Элемент для удаления найден
    else{
        Container * left_child = node->left;
        Container * right_child = node->right;
        delete node;
        if(right_child == nullptr) return left_child;
        Container * min = find_min(right_child);
        min->right = remove_min(right_child);
        min->left = left_child;
        return balance(min);
    }
    return balance(node);
}

#pragma region task specific

void Tree::insert(double weight){

}

Container * Tree::insert(double weight, Container * container){
    return new Container();
}

Container * Tree::find_place(double weight, Container * container){
    if (container == nullptr) return container;
    Container * best_place = nullptr;
    if (weight < container->available_space){
      best_place = find_place(weight, container->left);
    }
    else if (weight > container->available_space){
      best_place = find_place(weight, container->right);
    }
    if(best_place == nullptr) best_place = container;
    return best_place;
}

#pragma endregion task specific


#pragma endregion private