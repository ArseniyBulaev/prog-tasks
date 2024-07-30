#include <cstddef>
#include <iostream>

#include "heap.h"



int main(){
	size_t k = 5;
	std::vector<int> dates = {1783, 1804, 1918, 2001, 1865, 1941, 1776, 1945, 1492, 1963};
	std::vector<int> sorted_dates = heap_sort(dates);
	for(int date: sorted_dates){
		std::cout << date << std::endl;
	}
	Heap heap(dates);
	std::cout << k << " smallest elements:: ";
	for (size_t i = 1; i <= k; i++){
		std::cout << heap.extract_min();
		if(i != k) std::cout << " ";
	}
	std::cout << std::endl;
	
	return 0;
}