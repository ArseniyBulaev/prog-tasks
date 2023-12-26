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
private:
    AVLNode * head;
    static size_t get_height(AVLNode * node);
};