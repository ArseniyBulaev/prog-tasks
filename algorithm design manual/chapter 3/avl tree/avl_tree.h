#pragma once

#include <cstddef>
#include <vector>

struct AVLNode{
    int item;
    size_t height = 0;
    AVLNode * left = nullptr;
    AVLNode * right = nullptr;
    AVLNode(int item):item(item), height(1) {}
};

class AVLTree{
public:
    void insert(int item);
    void remove(int item);
    AVLTree(const std::vector<int> & items);
    AVLTree(const AVLTree & tree);
    ~AVLTree();
private:
    AVLNode * head = nullptr;
    static size_t get_height(AVLNode * node);
    static int get_balance_factor(AVLNode * node);
    static void restore_height(AVLNode * node);
    static AVLNode * left_rotation(AVLNode * node);
    static AVLNode * right_rotation(AVLNode * node);
    static AVLNode * balance(AVLNode * node);
    static void delete_tree(AVLNode * node);
    static AVLNode * create_from(AVLNode * node);
    static AVLNode * find_min(AVLNode * node);
    static AVLNode * remove_min(AVLNode * node);
    AVLNode * insert(int item, AVLNode * node);
    AVLNode * remove(int item, AVLNode * node);
};