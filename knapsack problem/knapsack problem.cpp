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

int knapsack_problem(int knapsack_size, const vector<Element> & elements){
    // Создадим таблицу с фиктивными элементами, чтобы было легче
    vector<vector<pair<string, int>>> table(elements.size() + 1);
    // Заполнение таблицы нулями, чтобы не делать это потом
    std::fill(table[0].begin(), table[0].end(), pair<string, int>{"", 0});
    for(vector<pair<string, int>> & row: table){
        row.resize(knapsack_size + 1);
        std::fill(row.begin(), row.begin() + 1, pair<string, int>{"", 0});
    }

   for (size_t i = 0; i < elements.size(); ++i){
    for (size_t j = 1; i < knapsack_size + 1; i++){
        if (elements[i].weight <= j){
          
            
        }
        else{
            table[i + 1][j] = table[i][j];
        }
    }
   }

        
           
        {
            /* code */
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

    return table[elements.size() - 1][table_weights_number].second;
}



int main(){
    const int knapsack_size = 4;
    const vector<Element> elements = {
        Element("laptop", 2000, 3),
        Element("guitar", 1500, 2),
        Element("record_play", 3000, 4)
    };

   knapsack_problem(knapsack_size, elements);
}