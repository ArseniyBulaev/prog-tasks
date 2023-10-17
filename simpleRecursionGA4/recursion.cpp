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

void recursiveMaxTest(){
    vector<vector<int>> tests = {{}, {1}, {1, 2, 3}, {10,10,10,10}, {1,2,3,4,6,1}};
    int max = -1;
    for (const vector<int> & test : tests){
       cout << recursiveMax(test, max);
       cout << endl;
    }
}

int recursiveMax(vector<int> array){
    
    if (array.size() == 0) return -1;

    if (array.size() == 2){
        return array[0] > array[1] ? array[0] : array[1];
    }
    
    int last_element = array.back();
    array.pop_back();
    int recursion_result = recursiveMax(array);
    return last_element > recursion_result ? last_element : recursion_result;
    
}

void recursiveMaxTest2(){
    vector<vector<int>> tests = {{}, {1}, {1, 2, 3}, {10,10,10,10}, {1,2,3,4,6,1}};
    for (const vector<int> & test : tests){
       cout << recursiveMax(test);
       cout << endl;
    }
}

int recursiveBinarySearch(const vector<int> & array, int smallest, int greatest, int item){
    if(array.size() == 0 || (smallest > greatest)) return -1;

    int mid = (smallest + greatest) / 2;

    if(array[mid] == item) return mid;
    if(array[mid] > item) greatest = mid - 1;
    else smallest = mid + 1;

    return recursiveBinarySearch(array, smallest, greatest, item);
}

void recursiveBinarySearchTest(){
    vector<vector<int>> tests = {{}, {1}, {1, 2, 3}, {10,10,10,10}, {1,2,3,4,6}};
    cout << "test1 :" << recursiveBinarySearch(tests[0], 0,0,1) << endl;
    cout << "test2 :" << recursiveBinarySearch(tests[1], 0,0,1) << endl;
    cout << "test3 :" << recursiveBinarySearch(tests[2], 0,2,2) << endl;
    cout << "test4 :" << recursiveBinarySearch(tests[3], 0,3,10) << endl;
    cout << "test5 :" << recursiveBinarySearch(tests[4], 0,4,3) << endl;
    cout << "test6 :" << recursiveBinarySearch(tests[4], 0,4,4) << endl;
    cout << "test7 :" << recursiveBinarySearch(tests[4], 0,4,2) << endl;
}

int main(){
    recursiveBinarySearchTest();
    return 0;
}