#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>

double average(const std::vector<double> & elements){
    double sum = 0;
    for (size_t i = 0; i < elements.size(); ++i){
        sum += elements[i];
    }
    return sum / elements.size();
}

double rounding_to_two_digits(double value){
    // Округление до двух знаков после запятой
    return static_cast<int>(value * 100.00) / 100.00;
}

double calculate_exchange_amount_some_guy(const std::vector<double> & student_amounts){
    if (student_amounts.empty()) return 0;

    // Вычисление среднего
    double avg = average(student_amounts);
   
    double pos = 0, neg = 0, diff = 0;
    for (double student_amount : student_amounts){
         double diff = rounding_to_two_digits(student_amount - avg);
         if (diff >= 0) {
				pos += diff;
			} else {
				neg += diff;
			}
    }

    return (pos >= -neg) ? pos : -neg;
}

double calculate_exchange_amount_my(const std::vector<double> & student_amounts){
    if (student_amounts.empty()) return 0;
    // Вычисление среднего
    double avg = average(student_amounts);
    double to_exchange = 0;
    for (double student_amount : student_amounts){
         if(student_amount > avg){
            to_exchange += rounding_to_two_digits(student_amount - avg);
         }
    }
    return to_exchange;
}

void the_trip_problem(){
    int n;
    double student_amount;
    while(true){
        std::cin >> n;
        if(n == 0) break;
        std::vector<double> student_amounts;
        for (size_t i = 0; i < n; ++i){
            std::cin >> student_amount;
            student_amounts.push_back(student_amount);
        }
        double must_be_exchanged_my = calculate_exchange_amount_my(student_amounts);
        double must_be_exchanged_some_guy = calculate_exchange_amount_some_guy(student_amounts);
        std::cout << "$" << std::fixed << std::setprecision(2) << must_be_exchanged_some_guy << std::endl;
        std::cout.unsetf(std::ios_base::floatfield);
        std::cout << (must_be_exchanged_my == must_be_exchanged_some_guy) << std::endl;
    }
}

int main(){
    std::ifstream in("input.txt");
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());
    the_trip_problem();
    return 0;
}