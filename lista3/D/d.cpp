#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <set>
using namespace std;

set<string> words;
string word = "";

int main() {
  char c;
  
  while(true) {
    if(!(cin.get(c))) break;

    if(!word.empty() && c == '\n' && *(word.end() - 1) == '-') {
      word.pop_back();
    
    } else if(isalpha(c) || c == '-') {
      word.push_back(tolower(c));
    
    } else if(!word.empty()){
      words.insert(word);
      word.clear();
    }
  }

  for(auto i : words) {
    cout << i << endl;
  }
  
  return 0;
}
