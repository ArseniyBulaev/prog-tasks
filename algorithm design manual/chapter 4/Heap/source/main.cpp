#include <cstddef>
#include <iostream>

#include "heap.h"



int main(){
	std::vector<int> dates = {1783, 1804, 1918, 2001, 1865, 1941, 1776, 1945, 1492, 1963};
	std::vector<int> sorted_dates = heap_sort(dates);
	for(int date: sorted_dates){
		std::cout << date << std::endl;
	}
	return 0;
}