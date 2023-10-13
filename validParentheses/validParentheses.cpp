#include<stack>
#include<unordered_map>
#include<string>

using std::stack;
using std::unordered_map;
using std::string;

bool isValid_Ugly(string s) {

    unordered_map<char, char> pairs = {
        {'[', ']'},
        {'(', ')'},
        {'{', '}'}
    };
    stack<char> curSeqOfBkt;
    for(size_t i = 0; i < s.size(); ++i){
        char curBkt = s[i];
        if(curBkt == '(' || curBkt == '[' || curBkt == '{'){
            curSeqOfBkt.push(curBkt);
        }
        else if (!curSeqOfBkt.empty()){

            if(pairs[curSeqOfBkt.top()] == curBkt){
                curSeqOfBkt.pop();
            }
            else{
                return false;
            }
        } 
        else return false; 

    }
    return curSeqOfBkt.empty();
}

#include<stack>
#include<unordered_map>

using std::stack;
using std::unordered_map;


bool isValid_Fast(string s) {

    unordered_map<char, char> pairs = {
        {'[', ']'},
        {'(', ')'},
        {'{', '}'}
    };
    stack<char> curSeqOfBkt;
    for(size_t i = 0; i < s.size(); ++i){
        char curBkt = s[i];
        if(curBkt == '(' || curBkt == '[' || curBkt == '{'){
            curSeqOfBkt.push(curBkt);
        }
        else if (curSeqOfBkt.empty() || pairs[curSeqOfBkt.top()] != curBkt){
            return false;
        }
        else{
            curSeqOfBkt.pop(); 
        }
    }   
    return curSeqOfBkt.empty();
}


bool isValid_prettyButSlow(string s) {
    stack<char> curSeqOfBkt;
    for(size_t i = 0; i < s.size(); ++i){
        char curBkt = s[i];
        if(curBkt == '(') {curSeqOfBkt.push(')');}
        else if(curBkt == '[') {curSeqOfBkt.push(']');}
        else if(curBkt == '{') {curSeqOfBkt.push('}');}
        else if (curSeqOfBkt.empty() || curSeqOfBkt.top() != curBkt){ return false;}
        else{curSeqOfBkt.pop();}
    }   
    return curSeqOfBkt.empty();
}