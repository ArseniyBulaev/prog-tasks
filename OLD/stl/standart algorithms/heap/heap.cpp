#include <algorithm>
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

void print(const vector<int> & elements){
    std::for_each(elements.begin(), elements.end(), [](int element) { cout << element << " ";});
    cout << endl;
}

vector<int> make_heap(vector<int> elements){
    std::make_heap(elements.begin(), elements.end());
    print(elements);
    return elements;
}

void push_heap(vector<int> elements, int element){
    elements = make_heap(elements);
    elements.push_back(element);
    std::push_heap(elements.begin(), elements.end());
    print(elements);
}

void pop_heap(vector<int> elements){
    elements = make_heap(elements);
    std::pop_heap(elements.begin(), elements.end());
    print(elements);
    cout << elements.back() << endl;  
}

int main(){
    vector<int> elements = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    make_heap(elements);
    push_heap(elements, 10);
    pop_heap(elements);
    return 0;
}