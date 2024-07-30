#include <set>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using std::set, std::vector;


set<set<int>> generate_subsets_of_some_length(const set<int> & superset, int k){
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
            for(const set<int> & k_minus_l_subset: generate_subsets_of_some_length(S_l_subset_difference, k - l)){
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

 set<set<set<int>>> generate_not_empty_subsets(const set<set<int>> superset){
    int n = superset.size();
    int number_of_all_subsets = static_cast<int>(pow(2, n));
    set<set<int>> subset;
    set<set<set<int>>> all_subsets;
    vector<set<int>> superset_v;
    for(const set<int> & element: superset) superset_v.push_back(element);

    for (size_t i = 0; i < number_of_all_subsets; ++i){
        for (size_t j = 0; j < n; ++j){
            if (i & (1 << j)){
                subset.insert(superset_v[j]);            
            }
        }
        if (subset.size() > 0) all_subsets.insert(subset);
        subset.clear(); 
    }

    return all_subsets;
}

// S - множество номеров
// l - количество совпадающих номеров, необходимых, чтобы выйграть приз
// k - количество номеров в билете
set<set<int>> lotto_problem(const set<int> & superset, int k, int l){
    set<set<int>> l_subsets = generate_subsets_of_some_length(superset, l); // Подмножества множества superset длины l
    set<set<int>> k_subsets = generate_subsets_of_some_length(superset, k); // Подмножества множества superset длины k
    set<set<set<int>>> all_possible_ticket_combinations =  generate_not_empty_subsets(k_subsets);
    set<set<int>> best;
    for(const set<set<int>> & ticket_combination : all_possible_ticket_combinations){
       set<set<int>> need_to_cover(l_subsets);
       for(const set<int> & ticket: ticket_combination){
             set<set<int>> buffer;
             set<set<int>> covered = check_coverage(superset, l, l_subsets, ticket);
             std::set_difference(need_to_cover.begin(), need_to_cover.end(),
                                covered.begin(), covered.end(),
                                std::inserter(buffer, buffer.end()));
            need_to_cover = buffer;
       }
       if (need_to_cover.empty()){
            if (!best.empty()){
                if(ticket_combination.size() < best.size()){
                    best = ticket_combination;
                }
            }else{
                best = ticket_combination;
            } 
       }  
    }
    return best;
}


int main(){
    set<int> superset = {1,2,3,4,5};
    int l = 2;
    int k = 3;
    set<set<int>> best_solution = lotto_problem(superset, k, l);
   
    
    return 0;
}