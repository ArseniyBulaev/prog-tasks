#pragma once

#include <cstddef>

struct AVLNode{
    int item;
    size_t height = 0;
    AVLNode * left = nullptr;
    AVLNode * right = nullptr;
    AVLNode * parent = nullptr;
    AVLNode(int item):item(item) {
         height = 1;
    };
};


class AVLTree{
public:
    void insert(int item);
private:
    AVLNode * head;
    void insert(AVLNode * node, int item);
};