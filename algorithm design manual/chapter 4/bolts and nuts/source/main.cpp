#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <unordered_map>

// Task size
const size_t task_size = 1;
// Random staff
auto rd = std::random_device {}; 
auto rng = std::default_random_engine { rd() };

int partition(std::vector<int> & s, int l, int h){
	int p; // Ведущий элемент
	int firsthigh; // Позиция для элементра разделителя
	p = h;
	firsthigh = l;
	for(int i = l; i < h; i++){
		if(s[i] < s[p]){
			std::swap(s[i], s[firsthigh]);
			firsthigh++;
		}
	}
	std::swap(s[p], s[firsthigh]);
	return firsthigh;
}


void partition_nuts_by_bolt(std::vector<int> & nuts
					, int nuts_lower_bound
					, int nuts_upper_bound
					, const std::vector<int> & bolts
					, const int pivot_bolt_index
					, std::unordered_map<int, size_t> & bolt_to_nut_index_relation){
	
	size_t first_high = nuts_lower_bound;
	int appropriate_nut_index;
	for(int i = nuts_lower_bound; i <= nuts_upper_bound; ++i){
		if(nuts[i] == bolts[pivot_bolt_index]) appropriate_nut_index = i;
			
		if(nuts[i] < bolts[pivot_bolt_index]){
			std::swap(nuts[i], nuts[first_high]);
			first_high++;
		}
	}

	// since than first_high = appropriate_nut_index
	std::swap(nuts[appropriate_nut_index], nuts[first_high]);
	bolt_to_nut_index_relation[bolts[pivot_bolt_index]] = first_high;
}


void recursive_step(std::vector<int> & nuts
				, int nuts_lower_bound
				, int nuts_upper_bound
				, const std::vector<int> & bolts
				, std::unordered_map<int, size_t> & bolt_to_nut_index_relation){

	if((nuts_upper_bound - nuts_lower_bound) > 0){
		std::uniform_int_distribution<std::mt19937::result_type> dist(nuts_lower_bound, nuts_upper_bound);
		int pivot_bolt_index = dist(rng);
		partition_nuts_by_bolt(nuts, nuts_lower_bound, nuts_upper_bound, bolts, pivot_bolt_index, bolt_to_nut_index_relation);
		recursive_step(nuts, nuts_lower_bound, pivot_bolt_index - 1, bolts, bolt_to_nut_index_relation);
		recursive_step(nuts, pivot_bolt_index + 1, nuts_upper_bound, bolts, bolt_to_nut_index_relation);
	}
	
}

std::unordered_map<int, size_t> find_pairs(const std::vector<int> & nuts, const std::vector<int> & bolts){
	std::vector<int> nuts_copy = nuts; // work with copy to know initial positions
	std::unordered_map<int, size_t> bolt_to_nut_index_relation;
	recursive_step(nuts_copy, 0, nuts_copy.size() - 1, bolts, bolt_to_nut_index_relation);
	return bolt_to_nut_index_relation;
}


int main(){
	// Create
	std::vector<int> bolts(task_size);
	std::iota(bolts.begin(), bolts.end(), 1);
	std::vector<int> nuts(task_size);
	std::iota(nuts.begin(), nuts.end(), 1);
	// Shuffle
	std::shuffle(std::begin(bolts), std::end(bolts), rng);
	std::shuffle(std::begin(nuts), std::end(nuts), rng);
	std::unordered_map<int, size_t> bolt_to_nut_index_relation = find_pairs(nuts, bolts);
	for(auto bolt_nut_index: bolt_to_nut_index_relation){
		std::cout << bolt_nut_index.first << " appropriates to nut:  " << nuts[bolt_nut_index.second] << std::endl; 
	}

	return 0;
} 