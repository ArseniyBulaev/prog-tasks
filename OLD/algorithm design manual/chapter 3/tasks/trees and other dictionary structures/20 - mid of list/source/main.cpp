#include <cstddef>
#include <iostream>
#include <cmath>

struct Node{
    Node * next = nullptr;
    int data = 0;
};

class List{
private:
    Node * _head = nullptr;
    size_t _size = 0;
public:
    size_t size(){
        return _size;
    }
    void insert(int data){
        Node * new_node = new Node{_head, data};
        _head = new_node;
        ++_size;
    }
    int find_mid(){
        // Если элементов чётное число, то средним элементом считаем size() / 2
        size_t mid_indx = static_cast<size_t>(ceil(size() / 2.0));
        size_t current_indx = 1;
        Node * current = _head;
        while(current_indx < mid_indx){
            current = current->next;
            ++current_indx;
        }
        if(current != nullptr){
            return current->data;
        } 
        else{
            std::cout << "the list is empty ";
            return -1;
        }
    }
    ~List(){
        Node * current = _head;
        while(current != nullptr){
            Node * buf = current->next;
            std::cout << "delete " << current->data << std::endl;
            delete current;
            current = buf;
        }
    }
};


int main(){
    List list;
    for(size_t i = 1; i <= 3; ++i){
        list.insert(i);
    }
    std::cout << "mid of the list: " << list.find_mid() << std::endl;
    return 0;
}