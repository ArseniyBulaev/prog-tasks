#include<iostream> 
#include<vector>

using namespace std;

void sort(vector<int> & elements, bool (*predicate) (int, int)){
    for(size_t i = 0; i < elements.size() ; ++i){
        for(size_t j = i + 1; j < elements.size(); ++j){
            if(predicate(elements[i], elements[j])){
                int tmp = elements[i];
                elements[i] = elements[j];
                elements[j] = tmp;
            }
        }
    }
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
    for (size_t i = 0; i < test.size(); ++i){
       print(test[i]);
       sort(test[i], predicate);
       print(test[i]);
    }
    return 0;
}