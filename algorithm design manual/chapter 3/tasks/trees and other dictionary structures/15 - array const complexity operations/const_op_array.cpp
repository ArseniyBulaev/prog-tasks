#include <stdexcept>

#include "const_op_array.h"

ConstOpArray::ConstOpArray(size_t n, size_t m):n(n), m(m){
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

bool ConstOpArray::search(int x){
    if(x < 2 || x > n - 1) return false; // В массиве хранятся элементы 1 < X < n
    size_t index_of_x = x - 2;
    if(initialized_locations[index_of_x]){
        size_t location = locations[index_of_x];
        return elements[location] == x; // Убеждаемся, что нужный элемент лежит в корректной позиции
    }
    else{
        return false;
    }
}


// Возвращаем истину, если элемент сохранен. Иначе - ложь
bool ConstOpArray::insert(int x){
    if(x < 2 || x > n - 1) return false; // Не храним такие элементы
    size_t index_of_x = x - 2;
    // Если элемент уже есть, то делать ничего не надо
    if(!initialized_locations[index_of_x]){
       if(!available_locations.empty()){
            size_t next_available_location = available_locations.top(); // получаем следующую свободную ячейку
            available_locations.pop();
            locations[index_of_x] = next_available_location; // Сохраняем индекс нового элемента
            elements[next_available_location] = x; // Сохраняем элемент
            initialized_locations[index_of_x] = true; // Теперь данная ячейка инициализирована
            return true; // Элемент добавлен
        }
        else{
            return false; // В массиве B не осталось свободного места
        }
        
    }
    return false;
}