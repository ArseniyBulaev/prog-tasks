#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

// Task size
const size_t task_size = 10;
// Random staff
auto rd = std::random_device {}; 
auto rng = std::default_random_engine { rd() };
std::uniform_int_distribution<std::mt19937::result_type> dist_task_size(0, task_size - 1);

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


void recursive_step(std::vector<int> & nuts
				, size_t nuts_lower_bound
				, size_t nuts_upper_bound
				, const std::vector<int> & bolts
				, const size_t pivot_bolt_index){

}

void find_pairs(const std::vector<int> & nuts, const std::vector<int> & bolts){
	std::vector<int> nuts_copy = nuts; // work with copy to know initial positions
	recursive_step(nuts_copy, 0, nuts_copy.size() - 1, bolts, dist_task_size(rng));
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



	return 0;
} 