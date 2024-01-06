#include "min_friendly_array.h"

void MinFriendlyArray::expand_smallest_elements_in_subseq(int new_element){
    // Индекс нового элемента равен размеру elements до вставки
    size_t indx_of_new_element = elements.size();
    for(std::vector<int> & subseq_for_some_element : smallest_elements_in_subseq){
        // Индекс наименьшего элемента в подпоследовательности  x_i ... x_n 
        // равен либо индексу текущему минимума, либо индексу нового элемента 
        int back = subseq_for_some_element.back();
        size_t indx_of_smallest = new_element < back ? indx_of_new_element : back;
        subseq_for_some_element.push_back(indx_of_smallest);
    } 
     // Добавляем новый элемент в список элементов
    elements.push_back(new_element);
}

void MinFriendlyArray::insert(int element){
    // Учитываем новый элемент при определении минимума в подпоследовательности 
    expand_smallest_elements_in_subseq(element);
}

MinFriendlyArray::MinFriendlyArray(const std::vector<int> & vec){
    for(int element : vec){
        insert(element);
    }
}