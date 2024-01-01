#pragma once

#include <cstddef>
#include <vector>

struct Container{
    double available_space = 1;
    size_t height = 0;
    Container * left = nullptr;
    Container * right = nullptr;
    Container(double weight):available_space(weight), height(1) {}
};

class Tree{
public:
    ~Tree();
private:
    Container * head = nullptr;
    static size_t get_height(Container * node);
    static int get_balance_factor(Container * node);
    static void restore_height(Container * node);
    static Container * left_rotation(Container * node);
    static Container * right_rotation(Container * node);
    static Container * balance(Container * node);
    static void delete_tree(Container * node);
    static Container * create_from(Container * node);
    static Container * find_min(Container * node);
    static Container * remove_min(Container * node);
    Container * insert(double weight, Container * node);
    Container * remove(double weight, Container * node);
    // task specific
public:
    void insert_object(double weight);
private:
    Container * insert_object(double weight, Container * node);
};