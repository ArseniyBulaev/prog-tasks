#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

double calculate_exchange_amount(const std::vector<float> & student_amounts){
    double sum = 0;
    double must_be_exchanged = 0;
    for (size_t i = 0; i < student_amounts.size(); ++i){
        sum += student_amounts[i];
    }
    double avg = sum / student_amounts.size();
    // std::cout << "avg without round " << avg << std::endl;
    // Округление до двух знаков после запятой
    double fraction = avg - std::floor(avg);
    if (fraction < 0.01){
        avg = std::floor(avg);
    }
    else{
        avg = std::round(avg * 100) / 100.0;
    }
    // std::cout << "avg after round: " << avg << std::endl;
    for (double student_amount : student_amounts){
        if(student_amount < avg){
            must_be_exchanged += avg - student_amount;
        }
    }
    return must_be_exchanged;
}

void the_trip_problem(){
    int n;
    double student_amount;
    while(std::cin >> n){
        std::vector<float> student_amounts;
        for (size_t i = 0; i < n; ++i){
            std::cin >> student_amount;
            student_amounts.push_back(student_amount);
        }
        double must_be_exchanged = calculate_exchange_amount(student_amounts);
        if (must_be_exchanged > 0.0){
            std::cout << "$" << std::fixed << std::setprecision(2) << must_be_exchanged << std::endl;
            std::cout.unsetf(std::ios_base::floatfield);
        }
        if (std::cin.eof()) break;
    }
}

int main(){
    the_trip_problem();
    return 0;
}