#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <unordered_map>
#include <cassert>

// Task size
const size_t task_size = 10;
// Random staff
auto rd = std::random_device {}; 
auto rng = std::default_random_engine { rd() };

int partition(std::vector<int> & s, int l, int h, int p){
	int firsthigh; // Позиция для элементра разделителя
	assert((void("p should equals to h"), p == h));
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


int main(){
	// Create
	std::vector<int> bolts(task_size);
	std::iota(bolts.begin(), bolts.end(), 1);
	std::vector<int> nuts(task_size);
	std::iota(nuts.begin(), nuts.end(), 1);
	// Shuffle
	std::shuffle(std::begin(bolts), std::end(bolts), rng);
	std::shuffle(std::begin(nuts), std::end(nuts), rng);
	
	for(int x: nuts){
		std::cout << x << " ";
	}
	std::cout << std::endl;
	std::cout << "pivot " << nuts[nuts.size() - 1] << std::endl;
	std::cout << "partition returned " << partition(nuts, 0, nuts.size() - 1, nuts.size() - 1) << std::endl;
	for(int x: nuts){
		std::cout << x << " ";
	}
	std::cout << std::endl;

	return 0;
} 