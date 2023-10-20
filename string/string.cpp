#include <iostream>
#include <cstring>

class String{
private:
    int size;
    char * symbols;
    
    void swap(String & another){
        std::swap(size, another.size);
        std::swap(symbols, another.symbols);
    }
public:
    String(int size = 0, char symbol = '\0'): size(size){
        symbols = new char[size];
        memset(symbols, symbol, size);
    }
    String(char symbol): size(1){
        symbols = new char[1];
        symbols[0] = symbol;
    }
    String(const String & another): size(another.size){
        symbols = new char[size];
        memcpy(symbols, another.symbols, size);
    }
    ~String(){

        delete [] symbols;
    }
    String & operator = (const String & another){
        String copy = another;
        swap(copy);
        return *this;
    }
    String operator + (const String & another){
        String concat(size + another.size);
        memcpy(concat.symbols, symbols, size);
        memcpy(concat.symbols + size, another.symbols, another.size);
        return concat;
    }

    friend String operator + (char symbol, const String & string);
};

String operator + (char symbol, const String & string){
    String concat(string.size + 1);
    concat.symbols[0] = symbol;
    memcpy(concat.symbols + 1, string.symbols, string.size);
    return concat;
}

int main(){

    String empty;
    String from_char_a(10, 'a');
    String from_char_b(10, 'b');
    String copy(from_char_a);
    String to_check_assignment_op;
    to_check_assignment_op = from_char_a;
    String concatenation = from_char_a + from_char_b;
    String string_plus_char = from_char_a + 'm';
    String char_plus_string = 'm' + from_char_a;


    return 0;
}