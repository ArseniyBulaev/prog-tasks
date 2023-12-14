#pragma once

#include <cstddef>

class Tree{
private:
    int item;
    Tree * parent = nullptr;
    Tree * left = nullptr;
    Tree * right = nullptr;
    void traverse(void (*operation) (Tree * node_p), Tree * node_p);
public:
    Tree() = default;
    Tree(int * array, size_t array_size);
    // O(h), h - tree height
    void insert_tree(Tree ** came_from, int item, Tree * parent);
    void traverse(void (*operation) (Tree * node_p));
    const Tree * get_parent() const;
    int get_item() const;
};

