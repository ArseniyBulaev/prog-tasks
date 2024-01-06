#include "min_friendly_array.h"

void MinFriendlyArray::expand_min_elements_in_subseq(int new_element){
    for(std::vector<int> & subseq_for_some_element : min_elements_in_subseq){
        // Проверяем меньше ли новый элемент текущего минимума
        int min = new_element < subseq_for_some_element.back() ? new_element : subseq_for_some_element.back();
        subseq_for_some_element.push_back(min);
    } 
}

void MinFriendlyArray::insert(int element){
    // Учитываем новый элемент при определении минимума в подпоследовательности 
    expand_min_elements_in_subseq(element);
    // Добавляем новый элемент в список элементов
    elements.push_back(element);
}

MinFriendlyArray::MinFriendlyArray(const std::vector<int> & vec){
    for(int element : vec){
        insert(element);
    }
}