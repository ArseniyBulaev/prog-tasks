#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <string>


std::string read_text(const std::string & file_path){
    std::ifstream input_file(file_path);
    std::string text;
    if(input_file.is_open()){
        input_file.seekg(0, std::ios::end);
        size_t size = input_file.tellg();
        text = std::string(size, ' ');
        input_file.seekg(0);
        input_file.read(&text[0], size); 
    }
    else{
        std::cout << "the file did not open" << std::endl;
    }
    return text;
}


void generate_english_alphabet(std::unordered_map<char, int> & alphabet,
std::unordered_map<int, char> & reverse_alphabet){
    for(char letter = 'a'; letter <= 'z'; ++letter){
        int letter_number = letter - 'a';
        alphabet[letter] = letter_number;
        reverse_alphabet[letter_number] = letter;
    }
}

// k - ключ, сдвиг
std::string chipher(const std::string & text, std::unordered_map<char, int> & alphabet, std::unordered_map<int,char> & reverse_alphabet, const int k){
    std::stringstream chiper_text_buffer;
    // n - мощность алфавита
    const int n  = alphabet.size();
    for(char symbol: text){
        auto search = alphabet.find(tolower(symbol));
        if(search != alphabet.end()){
            // p - номер буквы в алфавите, взятой из открытого текста
            int p = search->second;
            // c - номер буквы в алфавите в шифрованном тексте
            int c = (p + k) % n;
            // Шифр буквы
            char chipher_letter = reverse_alphabet.at(c);
            // Перевод в верхний регистр, если исходный символ в нём
            if(isupper(symbol)){
                chipher_letter = toupper(chipher_letter);
            }
            chiper_text_buffer << chipher_letter;
        }
        // Если символа нет в алфавите, то записываем его как есть
        else{
            chiper_text_buffer << symbol;
        }
    }
    return chiper_text_buffer.str();
}


int main(){
    std::unordered_map<char, int> alphabet;
    std::unordered_map<int, char> reverse_alphabet;
    const std::string text_path = "text\\input.txt";
    const int k = 3;
    generate_english_alphabet(alphabet, reverse_alphabet);
    std::string original_text = read_text(text_path);
    std::string cipher_text = chipher(original_text, alphabet, reverse_alphabet, k);
    return 0;
}