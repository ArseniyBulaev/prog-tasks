#pragma once

#include <cstddef>
#include <cmath>

using std::size_t;

struct Node{
    int key;
    int value;
    int sum_in_left_subtree = 0;
    int sum_in_right_subtree = 0;
    size_t height = 0;
    Node * left = nullptr;
    Node * right = nullptr;
    Node(int key, int value): key(key), value(value), height(1) {}
};

class SomeTree{
public:
    size_t size() { return tree_size;};
    void insert(int value);
    ~SomeTree();
private:
    Node * head = nullptr;
    size_t tree_size = 0;
    static size_t get_height(Node * node);
    static int get_balance_factor(Node * node);
    static void restore_height(Node * node);
    static Node * left_rotation(Node * node);
    static Node * right_rotation(Node * node);
    static Node * balance(Node * node);
    static void delete_tree(Node * node);
    Node * insert(int value, Node * node);
};