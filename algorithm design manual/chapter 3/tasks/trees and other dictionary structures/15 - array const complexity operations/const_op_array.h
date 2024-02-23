#include <stack>
#include <cstddef>

class ConstOpArray{
public:
    ConstOpArray(size_t n, size_t m){
        locations = new size_t[n];
        elements = new int[m];
        initialized_locations = new bool[n];
        available_locations = std::stack<size_t>();
        for (size_t i = 0; i < m; ++i){
            available_locations.push(i);
        }
    }
private:
    size_t n; // Правая граница диапазона
    size_t m; // Число элементов, которые можно хранить
    size_t * locations; // Позиции элементов в массиве B (Массив A)
    int * elements; // Элементы (Массив B)
    bool * initialized_locations; // Инициальзированные позиции
    std::stack<size_t> available_locations; // Позиции, в которых можно что-то сохранить
};