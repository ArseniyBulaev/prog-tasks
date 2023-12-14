#pragma once


class Tree{
    int item;
    Tree * parent;
    Tree * left;
    Tree * right;
    void insert_tree(Tree ** came_from, int item, Tree * parent);
};

