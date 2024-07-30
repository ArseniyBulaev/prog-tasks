#include <vector>
#include <iostream>

int partition(std::vector<int> & s, int l, int h);

void quicksort(std::vector<int> & s, int l, int h){
	int p; // Ведущий элемент
	if((h - l) > 0){
		p = partition(s, l, h);
		quicksort(s, l, p - (l + 1));
		quicksort(s, p + l + 1, h); 
	}
}

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
	std::vector<int> s = {2};
	quicksort(s, 0, s.size() - 1);
	for(int element : s) std::cout << element << " ";
	std::cout << std::endl;
	return 0;
} 