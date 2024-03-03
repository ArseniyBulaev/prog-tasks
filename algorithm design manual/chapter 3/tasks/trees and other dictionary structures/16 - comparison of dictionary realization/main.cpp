#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "IDictionary.h"
#include "ListDictionary.h"

std::stringstream get_text(const std::string & file_name){
    std::ifstream file_with_text(file_name);
    std::stringstream buffer;
    buffer << file_with_text.rdbuf();
    return buffer;
}

void perfomance_test(IDictionary & dictionary, const std::string & test_text){
    std::stringstream test_text_buffer = get_text(test_text);
    std::string word;
    while(test_text_buffer >> word){
        dictionary.insert(word);
    }
}


int main(){
    // Тестирование словаря на листе
    ListDictionary list_dictionary; 
    perfomance_test(list_dictionary, "test_text.txt");
    return 0;
}