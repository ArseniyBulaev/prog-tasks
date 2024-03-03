#pragma once

#include <cstddef>
#include <string>

struct Node
{
    std::string item;
    Node * parent = nullptr;
    Node * left = nullptr;
    Node * right = nullptr;
};


class Tree{
private:
    Node * head = nullptr;
    void traverse(void (*operation) (Node * node_p), Node * node_p);
    Node * search(Node * current, const std::string & target) const;
public:
    Tree() = default;
    void insert(Node ** came_from, const std::string & item, Node * parent);
    void insert(const std::string &item);
    bool search(const std::string & target) const;
    void traverse(void (*operation) (Node * node_p));
    ~Tree();
};

