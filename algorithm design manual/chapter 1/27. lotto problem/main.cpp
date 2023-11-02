#include <set>

using std::set;

// Способ проверки покрытия данным билетом l-подмножеств множества S, за которое может выдаваться приз
// S - множество номеров
// l_subsets - l-подмножества множества S
// ticket - лотерейный билет
set<int> check_coverage(const set<int> S, const set<int> &  l_subsets, const set<int> & ticket){
    int l = l_subsets.size(); // количество совпадающих номеров, необходимых, чтобы выйграть приз
    int k = ticket.size(); // количество номеров на каждом билете
    set<int> covered_l_subsets;
    // Для каждого подмножества l_subset из l_subsets
        // Рассматриваем пересение ticket и l_subset
        // Если колличество элементов равно l
                // ticket покрывает l_subset
                // covered_l_subsets.append(l_subset)
        // Расматриваем разность S и l
        // Для каждого (k - l)- подмножества разности S и l k_minus_l_subset 
            // Рассматриваем пересение ticket и (объёдинение k_minus_l_subset и l_subet)
            // Если колличество элементов равно l
                // ticket покрывает l_subset
                // covered_l_subsets.append(l_subset)
}