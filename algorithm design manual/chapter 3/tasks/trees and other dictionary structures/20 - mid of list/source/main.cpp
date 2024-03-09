#include <cstddef>
#include <iostream>

struct Node{
    Node * next = nullptr;
    int data = 0;
};

class List{
private:
    Node * _head;
    size_t _size;
public:
    size_t size(){
        return _size;
    }
    void insert(int data){
        Node * new_node = new Node{_head, data};
        _head = new_node;
        ++_size;
    }
    ~List(){
        Node * current = _head;
        while(current != nullptr){
            Node * buf = current->next;
            std::cout << current->data << std::endl;
            delete current;
            current = buf;
        }
    }
};


int main(){
    List list;
    for(size_t i = 1; i <= 10; ++i){
        list.insert(i);
    }
    return 0;
}