#include<iostream>
#include<vector>
using std::vector;
using std::cout, std::endl;

int recursiveSum(vector<int> array){
    if(array.size() == 0) return 0;
    if(array.size() == 1) return array[0];

    int last_element = array.back();
    array.pop_back();
    return last_element + recursiveSum(array);
}

void recursiveSumTest(){
    cout << (recursiveSum({1,2,3,4,5,6,7,8,9,10}) == 55) << endl;
    cout << (recursiveSum({}) == 0) << endl;
    cout << (recursiveSum({1}) == 1) << endl;
}

int recursiveCount(vector<int> array){
    if (array.empty()) return 0;
    array.pop_back();
    return 1 + recursiveCount(array);
}

void recursiveCountTest(){
    vector<vector<int>> tests = {{}, {1}, {1, 2, 3}, {10,10,10,10}};
    for (const vector<int> & test : tests)
    {
       cout << (recursiveCount(test) == test.size()) << endl;
    }
}


int recursiveMax(vector<int> array, int current_max){
    if(array.size() == 0) return current_max;
    if(array.back() > current_max) current_max = array.back();
    array.pop_back();
    return recursiveMax(array, current_max);
}

int recursiveMaxTest(){
    vector<vector<int>> tests = {{}, {1}, {1, 2, 3}, {10,10,10,10}, {1,2,3,4,6,1}};
    int max = -1;
    for (const vector<int> & test : tests){
       cout << recursiveMax(test, max);
       cout << endl;
    }
}

int main(){
    return 0;
}