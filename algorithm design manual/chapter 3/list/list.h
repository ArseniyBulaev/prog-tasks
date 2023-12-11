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
};
