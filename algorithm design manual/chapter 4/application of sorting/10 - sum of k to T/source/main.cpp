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
	const size_t n = S.size() - 1;
	// Indexes array size
	const int m = k - 1;
	std::vector<size_t> indexes(m, 0);
	std::iota(indexes.begin(), indexes.end(), 0);
	// S Sorting 
	std::sort(S.begin(), S.end());
	
	
	while(n  - indexes[0] >= m){
		// Print current subsequence
		print_subsequence(S, indexes);

		// Sum current subsequence
		int sum_of_k_minus_one = sum_by_indexes(S, indexes);
		
		// Search from next element
		if(std::binary_search(S.begin() + indexes.back() + 1, S.end(), T - sum_of_k_minus_one)){
			return true;
		}

		// Get next subsequence from S. Start from last element
		int i = 0;

		while((i < m - 1) && (indexes[m - 1 - i] >= n - 1 - i)){
			indexes[m - 1 - i] = 0;
			++i;
		}

		++indexes[m - 1 - i];

		if(i != 0){
			for (int j = m - i; j < m; j++)
			{
				indexes[j] = indexes[j - 1] + 1;
			}
		}
	}
	return false;
}



int main(){
	int T = 12;
	size_t n = 50;
	std::vector<int> S(n, 0);
	std::iota(S.begin(), S.end(), 1);
	size_t k = 3; 
	std::cout << (sum_of_k_to_T(S, k, T) ? "found" : "not found") << std::endl;
	return 0;
}