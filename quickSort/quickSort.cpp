#include<iostream>
#include <algorithm>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

vector<int> concatenate(const vector<int> & first, const vector<int> & second) {
	vector<int> concat;
	concat.reserve(first.size() + second.size());
	concat.insert(concat.end(), first.begin(), first.end());
	concat.insert(concat.end(), second.begin(), second.end());
	return concat;
}

vector<int> quickSortEasyWay(const vector<int> & elements) {
	// So ugly
	
	if (elements.size() < 2){
		return elements;
	}

	int pivot = 0;

	vector<int> greater, less;

	for (size_t i = 1; i < elements.size(); ++i){
		if (elements[i] > elements[pivot]){
			greater.push_back(elements[i]);
		}
		else {
			less.push_back(elements[i]);
		}
	}

	vector<int> sorted;
	sorted = concatenate(sorted, quickSortEasyWay(less));
	sorted.push_back(elements[pivot]);
	sorted = concatenate(sorted, quickSortEasyWay(greater));

	return sorted;
}

void print(const vector<int> & elements) {
	for (size_t i = 0; i < elements.size(); ++i){
		
		cout << elements[i];

		if (i < elements.size() - 1){
			cout << " ";
		}
	}

	cout << endl;
}

void testquickSortEasyWay() {
	vector<vector<int>> tests = { {}, {1}, {7,8,9,0}, {1,2,3}, {5, 13, 1, 8, 15} };
	for (const vector<int> & test : tests) {
		cout << "original: ";
		print(test);
		cout << "sorted: ";
		print(quickSortEasyWay(test));
		cout << endl;
	}
}

vector<int> merge(vector<int> & merged, vector<int> & first_part, vector<int> & second_part) {
	
	merged.clear();

	while (!first_part.empty() && !second_part.empty()){
		if (first_part[0] < second_part[0]){
			merged.push_back(first_part[0]);
			first_part.erase(first_part.begin());
		}
		else {
			merged.push_back(second_part[0]);
			second_part.erase(second_part.begin());
		}
	}

	if (first_part.empty()){
		merged.insert(merged.end(), second_part.begin(), second_part.end());
	}
	else {
		merged.insert(merged.end(), first_part.begin(), first_part.end());
	}


	return merged;
}

void recursionStep(vector<int> & elements) {
	
	if (elements.size() == 1){
		return;
	}

	if (elements.size() == 2){

		if (elements[0] > elements[1]){
			int tmp = elements[0];
			elements[0] = elements[1];
			elements[1] = tmp;
		}
		return;
	}

	int mid = elements.size() / 2;

	vector<int> left_part = { elements.begin(), elements.begin() + mid };
	vector<int> right_part = { elements.begin() + mid, elements.end() };

	recursionStep(left_part);
	recursionStep(right_part);

	merge(elements, left_part, right_part);
}




vector<int> quickSort(vector<int> elements) {

	if (!elements.empty()) { recursionStep(elements); }
	return elements;
}

void quickSortTest() {
	vector<vector<int>> tests = { {}, { 1 }, { 7,8,9,0 }, { 1,2,3 }, { 5, 13, 1, 8, 15 }, {3,2,1} };
	for (vector<int> & test : tests) {
		cout << "original: ";
		print(test);
		cout << "sorted: ";
		print(quickSort(test));
		cout << endl;
	}
}

int main() {
	quickSortTest();
	return 0;
}