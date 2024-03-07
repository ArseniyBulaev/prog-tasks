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

// k - ключ, шифр
std::string decipher(const std::string & cipher_text, const std::unordered_map<char,int> alphabet, const std::unordered_map<int,char> reverse_alphabet, const int k){
    std::stringstream text_buffer;
    // n - мощность алфавита
    const int n  = alphabet.size();
    for(char symbol: cipher_text){
        auto search = alphabet.find(tolower(symbol));
        if(search != alphabet.end()){
            // c - номер буквы в алфавите, взятой из шифрованного текста
            int c = search->second;
            // p - номер буквы в алфавите из открытого текста
            int p = (c - k + n) % n;
            // Буква в открытом тексте
            char letter = reverse_alphabet.at(p);
            // Перевод в верхний регистр, если исходный символ в нём
            if(isupper(symbol)){
                letter = toupper(letter);
            }
            text_buffer << letter;
        }
        // Если символа нет в алфавите, то записываем его как есть
        else{
            text_buffer << symbol;
        }
    }
    return text_buffer.str();
}

std::unordered_map<char, double> calculate_letter_frequency(const std::string & text){
    std::unordered_map<char, double> letter_to_frequency;
    int total_alphabet_letters_count = 0;
    for (char symbol: text){
        if(isalpha(symbol)){
            ++letter_to_frequency[tolower(symbol)];
            ++total_alphabet_letters_count;
        }
    }
    for(auto letter_and_its_frequency : letter_to_frequency){
        char letter = letter_and_its_frequency.first;
        double frequency = letter_and_its_frequency.second;
        letter_to_frequency[letter] = (frequency / total_alphabet_letters_count) * 100;
    }
    return letter_to_frequency;
}

int main(){
    std::unordered_map<char, double> english_letter_frequency = {
        {'e', 12.7},
        {'t', 9.06},
        {'a', 8.17},
        {'o', 7.51},
        {'i', 6.97},
        {'n', 6.75},
        {'s', 6.33},
        {'h', 6.09},
        {'r', 5.99},
        {'d', 4.25},
        {'l', 4.03},
        {'c', 2.78},
        {'u', 2.76},
        {'m', 2.41},
        {'w', 2.36},
        {'f', 2.23},
        {'g', 2.02},
        {'y', 1.97},
        {'p', 1.93},
        {'b', 1.49},
        {'v', 0.98},
        {'k', 0.77},
        {'x', 0.15},
        {'j', 0.15},
        {'q', 0.1},
        {'z', 0.7},
    };
    
    std::unordered_map<char, int> alphabet;
    std::unordered_map<int, char> reverse_alphabet;
    const std::string text_path = "text\\input.txt";
    const int k = 3;
    generate_english_alphabet(alphabet, reverse_alphabet);
    std::string original_text = read_text(text_path);
    std::string cipher_text = chipher(original_text, alphabet, reverse_alphabet, k);
    std::string decipher_text = decipher(cipher_text, alphabet, reverse_alphabet, k);
    std::cout << "cipher text == decipher text " << (original_text == decipher_text) << std::endl;
    std::unordered_map<char, double> letter_frequency = calculate_letter_frequency(original_text);
    return 0;
}