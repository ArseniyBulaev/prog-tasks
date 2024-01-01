#include <iostream>
#include <vector>
#include <numeric>

using std::cout, std::endl;
using std::vector;

class NumbersDictionary{
private:
    vector<size_t> numbers;
public:
    // Инициализация: O(n)
    // Могут храниться целые числа из конечного множества  1..n
    // 0 - пустой элемент
    NumbersDictionary(size_t n):numbers(n) {
        std::iota(std::begin(numbers), std::end(numbers), 1);
     };
    // Удаление: O(1)
    void remove(size_t element){
        numbers[element - 1] = 0;
    }
    // Поиск: O(1)
    bool search(size_t element){
        return numbers[element - 1] != 0;
    }
    // Вставка: O(1)
    void insert(size_t element){
        numbers[element - 1] = element;
    }
};



int main(){
    size_t n = 100;
    size_t test_element = 1;
    NumbersDictionary num_dict(n);
    cout << "search for "<< test_element << " : " << (num_dict.search(test_element) ? "It's here " : "It's not here") << endl;
    num_dict.remove(test_element);
    cout << "search for "<< test_element << " : " << (num_dict.search(test_element) ? "It's here " : "It's not here") << endl;
    num_dict.insert(test_element);
    cout << "search for "<< test_element << " : " << (num_dict.search(test_element) ? "It's here " : "It's not here") << endl;

    return 0;
}