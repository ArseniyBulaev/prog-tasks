#include <iostream>

int collatz_cycle_length(int n){
    int cycle_length = 1;
    while(n != 1){
        cycle_length += 1;
        if (n % 2 != 0){
            n = 3*n + 1;
        }else{
            n = n / 2;
        }
    }

    return cycle_length;
}


int main(){
    int a, b;
    while((std::cin >> a >> b)){
        bool is_a_greater_than_b = false;
        if(a > b){
            is_a_greater_than_b = true;
            int temp = a;
            a = b;
            b = temp;
        }
        int max_cycle_length = 0;
        for (int i = a; i <= b; ++i){
            int cycle_length = collatz_cycle_length(i);
            if(cycle_length > max_cycle_length){
                max_cycle_length = cycle_length;
            }
        }

        if(is_a_greater_than_b) std::cout << b << " " << a << " ";
        else  std::cout << a << " " << b << " ";
        std::cout << max_cycle_length << std::endl;
        if(std::cin.eof()) break;
    }
    return 0;
}