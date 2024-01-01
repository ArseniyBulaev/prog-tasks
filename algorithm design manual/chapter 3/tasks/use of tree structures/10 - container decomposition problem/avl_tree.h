#pragma once

#include <cstddef>
#include <vector>

struct AVLNode{
    double weight;
    size_t height = 0;
    AVLNode * left = nullptr;
    AVLNode * right = nullptr;
    AVLNode(double weight):weight(weight), height(1) {}
};

class AVLTree{
public:
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
    AVLNode * insert(double weight, AVLNode * node);
    AVLNode * remove(double weight, AVLNode * node);
    // task specific
public:
    void insert_object(double weight);
private:
    AVLNode * insert_object(double weight, bool is_place_found,  AVLNode * node);
};