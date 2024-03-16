#pragma once
struct Node{
    const char * data = nullptr;
    Node * next = nullptr;
};

class List{
private:
    Node * head = nullptr;
public:
    List() = default;
    List(const char ** strs, int size);
    List(const List & source);
    ~List();
    void print();
    Node * search(const char * target) const;
    void insert(char * element);
    Node * predecessor(char * element);
    void erase(char * element);
};
