#include <iostream>
#include <map>

int collatz_cycle_length(int n, const std::map<int,int> & previous_results){
    int cycle_length = 1;
    while(n != 1){
        if (previous_results.find(n) != previous_results.end()){
            cycle_length += previous_results.at(n) - 1;
            break;
        }
        
        cycle_length += 1;
        if (n % 2 != 0){
            n = 3*n + 1;
        }else{
            n = n / 2;
        }
    }

    return cycle_length;
}

void three_n_plus_one_problem(){
    int a, b;
    std::map<int,int> previous_results;

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
            int cycle_length = collatz_cycle_length(i, previous_results);
            previous_results[i] = cycle_length;
            if(cycle_length > max_cycle_length){
                max_cycle_length = cycle_length;
            }
        }

        if(is_a_greater_than_b) std::cout << b << " " << a << " ";
        else  std::cout << a << " " << b << " ";
        std::cout << max_cycle_length << std::endl;
        if(std::cin.eof()) break;
    }
}

int main(){
    three_n_plus_one_problem();
    return 0;
}