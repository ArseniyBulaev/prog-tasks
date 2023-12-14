#pragma once

#include <cstddef>

class Tree{
private:
    int item;
    Tree * parent = nullptr;
    Tree * left = nullptr;
    Tree * right = nullptr;
public:
    Tree() = default;
    Tree(int * array, size_t array_size);
    // O(h), h - tree height
    void insert_tree(Tree ** came_from, int item, Tree * parent);
};

