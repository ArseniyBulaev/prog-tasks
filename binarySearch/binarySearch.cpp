#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binarySearch(const vector<int> & array, int item){
    int head = 0, tail = array.size() - 1;
    int mid;

    while(head <= tail){

         mid = (head + tail) / 2;

        if(array[mid] == item){
            return mid;
        }
        if(array[mid] < item){
            head = mid + 1;
        }
        else{
            tail = mid - 1;
        }
    }

    return -1;
}


int main(){
 
    cout << binarySearch({}, 1) << endl;
    cout << binarySearch({1}, 1) << endl;
    cout << binarySearch({2}, 1) << endl;
    cout << binarySearch({1,2,3,4}, 1) << endl;
    cout << binarySearch({1,2,3,4, 6, 9, 17}, 6) << endl;

    return 0;
}