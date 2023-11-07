#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <limits>
#include <sstream>

using std::cout, std::cin, std::endl;
using std::string;
using std::vector, std::map;

vector<int> read_votes(int number_of_challengers, string line) {
  int vote;
  vector<int> votes;
  std::istringstream iss(line);
  for (size_t i = 0; i < number_of_challengers; ++i){
    iss >> vote;
    votes.push_back(vote);
  }
  return votes;
}


string australian_voting(){
    // Ввод числа кандидатов
    int number_of_challengers;
    cin >> number_of_challengers;
    if (number_of_challengers == 0) return "";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Считывание кандидатов
    vector<string> challengers;
    for (size_t i = 0; i < number_of_challengers; ++i)
    {
        string challenger;
        if(std::getline(cin, challenger)) challengers.push_back(challenger);
    }
    // Считывание голосов
    vector<vector<int>> voters;
    std::string line;
    while(std::getline(cin, line) && !line.empty()){
        voters.push_back(read_votes(number_of_challengers, line));
    }
    // Первоначальный подсчёт
    map<int, vector<int>> challenger_to_voter;
    for(size_t i = 0; i < voters.size(); ++i){
      challenger_to_voter[voters[i][0]].push_back(i); 
    }
    // Пересчёт по австралийской системе
    vector<bool> dropped_out(number_of_challengers, false);
    int winer = -1;
    do{
      int minimum_number_of_voters = voters.size();
      int maximum_number_of_voters = 0;
      for(const std::pair<int, vector<int>> & record: challenger_to_voter){
        if (!dropped_out[record.first - 1])
        {
          double challenger_percent = static_cast<double>(record.second.size()) / voters.size();
          if(record.second.size() < minimum_number_of_voters){
            minimum_number_of_voters = record.second.size();
          }
          if(record.second.size() > maximum_number_of_voters){
            maximum_number_of_voters = record.second.size();
          }
          if (challenger_percent > 0.5){
            winer = record.first - 1;
          }
        }

      }

      // Найден победитель
      if(winer != -1){break;}

      if (minimum_number_of_voters == maximum_number_of_voters){
        string draw;
         for(const std::pair<int, vector<int>> & record: challenger_to_voter){
          if (!dropped_out[record.first - 1])
          {
            draw += challengers[record.first - 1] + "\n";
          }
         } 
        return draw;
      }
      

      // Исключение кандидатов с наименьшим числом голосов
      for(const std::pair<int, vector<int>> & record: challenger_to_voter){
        if(record.second.size() == minimum_number_of_voters){
          // Кандидат больше не учитывается
          dropped_out[record.first - 1] = true;
        }
      }

      // Пересчёт голосов Исключённых кандидатов
      for(size_t i = 0; i < dropped_out.size(); ++i){
            int voter_idx = i + 1;
            if(dropped_out[i]){  
              int vote_idx = 0;
              while (dropped_out[voters[voter_idx][vote_idx] - 1]){++vote_idx;}
              challenger_to_voter[voters[voter_idx][vote_idx]].push_back(voter_idx);
            }
          challenger_to_voter[voter_idx].clear();
      }
    }while(true);
    
    return challengers[winer] + "\n";
}

int main(){
    // std::ifstream in("input.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf();
    // cin.rdbuf(in.rdbuf());
    int number_of_votes;
    cin >> number_of_votes;

    for (size_t i = 0; i < number_of_votes; ++i)
    {
       std::cout << australian_voting() << endl;
    }
    
    return 0;
}