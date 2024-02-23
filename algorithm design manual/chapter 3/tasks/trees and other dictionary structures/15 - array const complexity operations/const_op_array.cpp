#include "const_op_array.h"

ConstOpArray::ConstOpArray(size_t n, size_t m){
    locations = new size_t[n];
    elements = new int[m];
    initialized_locations = new bool[n]{false}; // Сначала ничего не инициализировано
    available_locations = std::stack<size_t>();
    for (size_t i = 0; i < m; ++i){
        available_locations.push(i); // При создании доступны все ячейки
    }
}

ConstOpArray::~ConstOpArray(){
    delete [] locations;
    delete [] elements;
    delete [] initialized_locations;
}