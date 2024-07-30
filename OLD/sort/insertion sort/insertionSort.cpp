#include<iostream>
#include<vector>
using namespace std;

vector<int> sort(vector<int> elements, bool (* predicate) (int, int)) {
    vector<int>sorted;

    while (elements.size()){

        int best_index = 0;

        for (size_t i = 1; i < elements.size(); ++i){
        
            if(predicate(elements[i], elements[best_index])){
                
                best_index = i;
            }
        }

        sorted.push_back(elements[best_index]);
        elements.erase(elements.begin() + best_index);
    }
    
    return sorted;
    
}

void print(const vector<int> & elements){
    for (size_t i = 0; i < elements.size(); ++i){
        cout << elements[i];
        cout << (i < elements.size() - 1 ? " " : "\n");
    }
}

bool predicate(int a, int b){
    return a > b;
}

int main(){


    
    vector<vector<int>> test = {{1,7,3} , {}, {1}, {1, 2}, {3, 4, 5}, {7,3,1,0}};
    vector<int> sorted;

    for (size_t i = 0; i < test.size(); ++i){
       print(test[i]);
       sorted = sort(test[i], predicate);
       print(sorted);
    }
    return 0;
}