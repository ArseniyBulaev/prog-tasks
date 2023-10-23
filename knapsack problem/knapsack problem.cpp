#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>


using std::vector, std::unordered_map;
using std::string;
using std::cout, std::endl;
using std::pair;

struct Element{
    string name;
    int price;
    int weight;
    Element(string name, int price, int weight): name(name), price(price), weight(weight) {}
};

bool compare(const Element & i, const Element & j) {
  return i.weight < j.weight;
}

int knapsack_problem(int knapsack_max_weight, const vector<Element> & elements){
    // Поиск элемента с наименьшим весом, чтобы веса в таблице начинались с веса этого элемента
    const Element & lightest_element = *std::min_element(elements.begin(), elements.end(), compare);
    // Создадим таблицу с фиктивными элементами, чтобы было легче
    vector<vector<pair<string, int>>> table(elements.size() + 1);
    // Заполнение таблицы нулями, чтобы не делать это потом
    std::fill(table[0].begin(), table[0].end(), pair<string, int>{"", 0});
    int number_of_weights = knapsack_max_weight - lightest_element.weight + 1;
    for(vector<pair<string, int>> & row: table){
        row.resize(number_of_weights);
        std::fill(row.begin(), row.begin() + 1, pair<string, int>{"", 0});
    }

    for (size_t i = 0; i < elements.size(); ++i){
        for (size_t j = 0; j < number_of_weights; ++j){
            if (elements[i].weight <= j + lightest_element.weight){
                int current_price = elements[i].price;
                string current_elements = elements[i].name;
                int available_weight =  j + lightest_element.weight - elements[i].weight;
                if (available_weight - lightest_element.weight >= 0){
                    current_price += table[i][available_weight - lightest_element.weight].second;
                    current_elements += "," + table[i][available_weight - lightest_element.weight].first;
                }

                if (current_price > table[i][j].second){
                    table[i + 1][j].first = current_elements;
                    table[i + 1][j].second = current_price;
                }
                else{
                    table[i + 1][j].first = table[i][j].first;
                    table[i + 1][j].second = table[i][j].second;
                }
            }
            else{
                table[i + 1][j].first = table[i][j].first;
                table[i + 1][j].second = table[i][j].second;
            }
        
        }
    }
              
        
    int row_number = 0;

    for(const vector<pair<string, int>> & row: table){
        cout << "row: " << row_number << endl;
        for(const pair<string, int> & table_element: row){
            cout << "elments: " << table_element.first << " price: " << table_element.second << "\t";
        }
        cout << endl;
        row_number++;
    }

    return 0;
}




int main(){
    const int knapsack_size = 4;
    const vector<Element> elements = {
        Element("laptop", 2000, 3),
        Element("guitar", 1500, 1),
        Element("record_play", 3000, 4)
    };

   knapsack_problem(knapsack_size, elements);
}