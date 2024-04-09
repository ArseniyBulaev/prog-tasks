#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <numeric>

int sum_by_indexes(const std::vector<int> & S, const std::vector<size_t> & indexes){
	int sum = 0;
	for(size_t index : indexes){
			sum += S[index];
	}
	return sum;
}

void print_subsequence(const std::vector<int> & S, const std::vector<size_t> & indexes){
	std::cout << "current subsequence: ";
	for(size_t index : indexes){
			std::cout << S[index] << " ";
	}
	std::cout << std::endl;
}

bool sum_of_k_to_T(std::vector<int> S, size_t k, int T){
	// Initialize vector
	const size_t n = S.size();
	// Indexes array size
	const int m = k - 1;
	std::vector<size_t> indexes(m, 0);
	std::iota(indexes.begin(), indexes.end(), 0);
	// S Sorting 
	std::sort(S.begin(), S.end());
	
	
	while(n - 1 - indexes[0] >= m){
		// Print current subsequence
		print_subsequence(S, indexes);

		// Sum current subsequence
		int sum_of_k_minus_one = sum_by_indexes(S, indexes);
		
		// Search from next element
		if(std::binary_search(S.begin() + indexes.back() + 1, S.end(), T - sum_of_k_minus_one)){
			return true;
		}

		// Get next subsequence from S
		int i = 0;
		// Wrong condition
		while(!(indexes[m - i - 1] < n - 1 - i) ){
			indexes[m - i - 1] = indexes[m - i - 2] + 2;
			++i;

		}
		++indexes[m - i - 1];
	}
	return false;
}



int main(){
	int T = 30;
	std::vector<int> S = {1,2,3,4};
	size_t k = 4; 
	std::cout << (sum_of_k_to_T(S, k, T) ? "found" : "not found") << std::endl;
	return 0;
}