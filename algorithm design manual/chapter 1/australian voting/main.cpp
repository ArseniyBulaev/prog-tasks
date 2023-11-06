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
    string winer;
    // Ввод числа кандидатов
    int number_of_challengers;
    cin >> number_of_challengers;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Считывание кандидатов
    vector<string> challengers;
    for (size_t i = 0; i < number_of_challengers; ++i)
    {
        string challenger;
        if(std::getline(cin, challenger)) challengers.push_back(challenger);
    }
    // Считывание голосов
    vector<vector<int>> votes;
    std::string line;
    while(std::getline(cin, line)){
        votes.push_back(read_votes(number_of_challengers, line));
    }
    
    
    
    
    return winer;
}

int main(){
    std::ifstream in("input.txt");
    std::streambuf *cinbuf = std::cin.rdbuf();
    cin.rdbuf(in.rdbuf());
    int number_of_votes;
    cin >> number_of_votes;

    for (size_t i = 0; i < number_of_votes; ++i)
    {
       australian_voting();
    }
    
    return 0;
}