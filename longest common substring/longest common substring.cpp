#include<string>
#include<iostream>
#include<vector>

using std::string;
using std::vector;
using std::pair;
using std::cout, std::endl;

string longest_common_substring(const string & first, const string & second){
    vector<int> table((first.size() + 1) * (second.size() + 1));
    string max_substring;
        
    for (size_t i = 1; i < first.size() + 1; ++i){
        for (size_t j = 1; j < second.size() + 1; ++j){
            if (first[i - 1] == second[j - 1]){
                if((i - 1) == (j - 1)){
                    table[i*(first.size() + 1) + j] = 1 + table[(i-1)*(first.size() + 1) + j - 1];
                    max_substring += first[i - 1];
                }
            }
        }
    }
    
    cout << "Table: " << endl;
    for (size_t i = 1; i < first.size() + 1; ++i){
        for (size_t j = 1; j < second.size() + 1; ++j){
            cout << table[i * (first.size() + 1) +j] << "\t";
        }
        cout << endl;
    }
    
    return max_substring;
}

int main(){
    string first = "fish";
    string second = "vista";
    string max_substring = longest_common_substring(first, second);
    cout << "longest common substring: " <<  max_substring << endl;

    return 0;
}