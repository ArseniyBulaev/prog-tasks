#include <stack>
#include <cstddef>

class ConstOpArray{
private:
    int n; // Правая граница диапазона
    int m; // Число элементов, которые можно хранить
    size_t * locations; // Позиции элементов в массиве B (Массив A)
    int * elements; // Элементы (Массив B)
    bool * initialized_locations; // Инициальзированные позиции
    std::stack<size_t> available_locations; // Позиции, в которых можно что-то сохранить
};