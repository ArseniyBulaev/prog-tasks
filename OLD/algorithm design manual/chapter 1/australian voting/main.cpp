#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <limits>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::map;

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
    vector<vector<int>> voter_votes;
    std::string line;
    while(std::getline(cin, line) && !line.empty()){
        voter_votes.push_back(read_votes(number_of_challengers, line));
    }
    // Первоначальный подсчёт
    map<int, vector<int>> challenger_to_voter;
    for(size_t i = 0; i < voter_votes.size(); ++i){
      challenger_to_voter[voter_votes[i][0]].push_back(i); 
    }
    // Пересчёт по австралийской системе
    map<int, bool> dropped_out;
    for (size_t i = 1; i <= number_of_challengers; i++){
      dropped_out[i] = false;
    }
    
    int winer = -1;
    do{
      int minimum_number_of_voters = voter_votes.size();
      int maximum_number_of_voters = 0;
      for(const std::pair<int, vector<int>> & record: challenger_to_voter){
        if (!dropped_out[record.first])
        {
          double challenger_percent = static_cast<double>(record.second.size()) / voter_votes.size();
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
          if (!dropped_out[record.first])
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
          dropped_out[record.first] = true;
        }
      }

      // Пересчёт голосов Исключённых кандидатов
      for(size_t challenger_idx = 1; challenger_idx <= dropped_out.size(); ++challenger_idx){
          
            if(dropped_out[challenger_idx]){  
              int vote_idx = 0;
              for(int voter_idx: challenger_to_voter[challenger_idx]){
                const vector<int> & votes = voter_votes[voter_idx];
                for(int vote : votes){
                  if(!dropped_out[vote]){
                    challenger_to_voter[vote].push_back(voter_idx);
                    break;
                  }
                }  
              }
              challenger_to_voter.erase(challenger_idx);
            }
          
      }
    }while(true);
    
    return challengers[winer] + "\n";
}

int main(){
    std::ifstream in("input.txt");
    std::streambuf *cinbuf = std::cin.rdbuf();
    cin.rdbuf(in.rdbuf());
    int number_of_votes;
    cin >> number_of_votes;

    for (size_t i = 0; i < number_of_votes; ++i)
    {
      std::cout << australian_voting();
      if(i < (number_of_votes - 1)){
        cout << endl;
      } 
    }
    
    return 0;
}