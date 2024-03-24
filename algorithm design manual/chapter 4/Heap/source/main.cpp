#include <cstddef>
#include "heap.h"


int main(){
	std::vector<int> dates = {1783, 1804, 1918, 2001, 1865, 1941, 1776, 1945, 1492, 1963};
	Heap<int> heap(dates);
	return 0;
}