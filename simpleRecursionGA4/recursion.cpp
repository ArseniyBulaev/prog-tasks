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

int main(){

    
    

    return 0;
}