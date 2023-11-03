#include <set>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using std::set, std::vector;


set<set<int>> generate_subsets(const set<int> & superset, int k){
    int n = superset.size();
    int number_of_all_subsets = static_cast<int>(pow(2, n));
    set<int> subset;
    set<set<int>> all_subsets;
    vector<int> superset_v;
    for(int element: superset) superset_v.push_back(element);

    for (size_t i = 0; i < number_of_all_subsets; ++i){
        for (size_t j = 0; j < n; ++j){
            if (i & (1 << j)){
                subset.insert(superset_v[j]);            
            }
        }
        if (subset.size() == k) all_subsets.insert(subset);
        subset.clear(); 
    }

    return all_subsets;
}

// Способ проверки покрытия данным билетом l-подмножеств множества S, за которое может выдаваться приз
// S - множество номеров
// l - количество совпадающих номеров, необходимых, чтобы выйграть приз
// l_subsets - l-подмножества множества S
// ticket - лотерейный билет
set<set<int>> check_coverage(const set<int> & S, int l,  const set<set<int>> &  l_subsets, const set<int> & ticket){
    int k = ticket.size(); // количество номеров на каждом билете
    set<set<int>> covered_l_subsets;
    for(const set<int> & l_subset: l_subsets){
        // Рассматриваем пересение ticket и l_subset
        set<int> ticket_l_subset_intersection;
        std::set_intersection(l_subset.begin(), l_subset.end(),
                            ticket.begin(), ticket.end(),
                            std::inserter(ticket_l_subset_intersection, ticket_l_subset_intersection.begin()));
        if(ticket_l_subset_intersection.size() == l)
                // ticket покрывает l_subset
                covered_l_subsets.insert(l_subset);
        else{
            set<int> S_l_subset_difference;
            std::set_difference(S.begin(), S.end(),
                                l_subset.begin(), l_subset.end(),
                                std::inserter(S_l_subset_difference, S_l_subset_difference.begin()));
            // Для каждого (k - l)- подмножества разности S и l k_minus_l_subset
            for(const set<int> & k_minus_l_subset: generate_subsets(S_l_subset_difference, k - l)){
                // Рассматриваем пересение ticket и (объёдинение k_minus_l_subset и l_subet)
                set<int> k_minus_l_subset_l_subset_union;
                std::set_union(k_minus_l_subset.begin(), k_minus_l_subset.end(),
                                l_subset.begin(), l_subset.end(),
                                std::inserter(k_minus_l_subset_l_subset_union, k_minus_l_subset_l_subset_union.begin()));
                set<int> ticket_k_minus_l_subset_l_subset_union_intersection;
                std::set_intersection(k_minus_l_subset_l_subset_union.begin(), k_minus_l_subset_l_subset_union.end(),
                                ticket.begin(), ticket.end(),
                                std::inserter(ticket_k_minus_l_subset_l_subset_union_intersection, ticket_k_minus_l_subset_l_subset_union_intersection.begin()));
                // Если колличество элементов равно l
                if(ticket_k_minus_l_subset_l_subset_union_intersection.size() == l)
                    // ticket покрывает l_subset
                    covered_l_subsets.insert(l_subset);
                    break;
            }
        }        
    }
    return covered_l_subsets;  
}


int main(){
    set<int> superset = {1,2,3,4,5};
    int l = 2;
    set<set<int>> covered_subsets = check_coverage(superset, l, generate_subsets(superset, l), {1, 2, 3});
    return 0;
}