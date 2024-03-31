#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

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



int main(){
	// Create
	size_t task_size = 10;
	std::vector<int> bolts(task_size);
	std::iota(bolts.begin(), bolts.end(), 1);
	std::vector<int> nuts(task_size);
	std::iota(nuts.begin(), nuts.end(), 1);
	// Shuffle
	auto rd = std::random_device {}; 
	auto rng = std::default_random_engine { rd() };
	std::shuffle(std::begin(bolts), std::end(bolts), rng);
	std::shuffle(std::begin(nuts), std::end(nuts), rng);

	return 0;
} 