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

private:
    AVLNode * head;
    static size_t get_height(AVLNode * node);
    static int get_balance_factor(AVLNode * node);
    static void restore_height(AVLNode * node);
    static AVLNode * left_rotation(AVLNode * node);
    static AVLNode * right_rotation(AVLNode * node);
    static AVLNode * balance(AVLNode * node);
    AVLNode * insert(int item, AVLNode * node);
};