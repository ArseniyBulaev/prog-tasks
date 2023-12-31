#pragma once

#include <cstddef>
#include <vector>

struct AVLNode{
    int item;
    size_t height = 0;
    AVLNode * left = nullptr;
    AVLNode * right = nullptr;
    AVLNode(int item):item(item), height(1) {}
    // Task specific
    size_t left_branch_size = 0;
    size_t right_branch_size = 0;
};

class AVLTree{
public:
    void insert(int item);
    void remove(int item);
    void traverse(void(*operation)(AVLNode * node));
    AVLTree(const std::vector<int> & items);
    AVLTree(const AVLTree & tree);
    ~AVLTree();
    // Task specific
    static AVLTree merge(AVLTree t1, AVLTree t2);
    AVLTree() = default;
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
    void traverse(void(*operation)(AVLNode * node), AVLNode * node);
    // Task specific
    static size_t  get_branch_size(AVLNode * node);
    static AVLNode * restore_branch_size(AVLNode * node);
    bool is_empty(AVLNode * node);
    static AVLNode * find_max(AVLNode * node);
    static AVLNode merge(AVLNode * t1, AVLNode * t2);
};