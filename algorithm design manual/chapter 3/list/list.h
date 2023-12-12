#pragma once
struct Node{
    char * data;
    Node * next;
};

class List{
private:
    Node * head;
public:
    List(char ** strs, int size);
    ~List();
    void print();
    Node * search(const char * target) const;
    void insert(char * element);
    Node * predecessor(char * element);
    void erase(char * element);
};
