#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::stringstream get_text(const std::string & file_name){
    std::ifstream file_with_text(file_name);
    std::stringstream buffer;
    buffer << file_with_text.rdbuf();
    return buffer;
}


int main(){
    return 0;
}