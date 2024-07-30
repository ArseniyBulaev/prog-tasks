#include "smallest_friendly_array.h"

void SmallestFriendlyArray::expand_smallest_elements_in_subseq(int new_element){
    // Индекс нового элемента равен размеру elements до вставки
    size_t indx_of_new_element = elements.size();
    for(std::vector<size_t> & subseq_for_some_element : smallest_elements_in_subseq){
        // Индекс наименьшего элемента в подпоследовательности  x_i ... x_n 
        // равен либо индексу текущему минимума, либо индексу нового элемента
        size_t indx_of_smallest = indx_of_new_element;
        if(!subseq_for_some_element.empty()){
            size_t back = subseq_for_some_element.back();
            if(elements[back] < new_element) indx_of_smallest = back;
        }
        subseq_for_some_element.push_back(indx_of_smallest);
    } 
     // Добавляем новый элемент в список элементов
    elements.push_back(new_element);
    smallest_elements_in_subseq.push_back({indx_of_new_element});
}


SmallestFriendlyArray::SmallestFriendlyArray(const std::vector<int> & vec){
    // Инициализация
    elements = std::vector<int>();
    smallest_elements_in_subseq = std::vector<std::vector<size_t>>();

    for(int element : vec){
        insert(element);
    }
}

void SmallestFriendlyArray::insert(int element){
    // Учитываем новый элемент при определении минимума в подпоследовательности 
    expand_smallest_elements_in_subseq(element);
}

int SmallestFriendlyArray::get_smallest_between(size_t i, size_t j){
    size_t indx_of_smallest = smallest_elements_in_subseq[i][j - i];
    return elements[indx_of_smallest];
}