#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>

#include "IDictionary.h"
#include "ListDictionary.h"
#include "BinaryTreeDictionary.h"

std::stringstream get_text(const std::string & file_name){
    std::ifstream file_with_text(file_name);
    std::stringstream buffer;
    buffer << file_with_text.rdbuf();
    return buffer;
}

void perfomance_test(IDictionary & dictionary, const std::string & test_text, const std::string & dict_type){
    std::stringstream test_text_buffer = get_text(test_text);
    std::string word;
    auto start = std::chrono::steady_clock::now();
    while(test_text_buffer >> word){
        dictionary.insert(word);
    }
    auto end = std::chrono::steady_clock::now();

    auto execution_time = end - start;
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(execution_time);
    std::cout << "execution time of " << dict_type << ": " << execution_time.count() << " ms" <<  std::endl;
}


int main(){
    // Тестирование словаря на листе
    ListDictionary list_dictionary; 
    perfomance_test(list_dictionary, "test_text.txt", "list dictionary");
    // Тестирование словаря на бинарном дереве
    BinaryTreeDictionary binary_tree_dictionary;
    perfomance_test(binary_tree_dictionary, "test_text.txt", "binary tree dictionary");
    return 0;
}