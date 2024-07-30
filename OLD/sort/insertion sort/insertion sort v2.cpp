#include <iostream>


void insertion_sort (char * string, int n){
    int j;
    for (int i = 1; i < n; ++i){
        j = i;
        while ((j > 0) && (string[j] < string[j - 1])){
            std::swap(string[j], string[j - 1]);
            --j;
        }
    }
}

int main(){
    char string [] = "insertionsort";
    int n = sizeof(string);
    for(int i = 0; i < n; ++i) { std::cout << string[i]; }
    std::cout << std::endl << "n =" << n << std::endl;
    insertion_sort(string, n);
    for(int i = 0; i < n; ++i) { std::cout << string[i]; }
    std::cout << std::endl;
    return 0;
}