#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

int main() {
  string word;
  cin >> word;
  
  for (int i = 0; i < word.size(); i++) {
    char a = asciitolower(word[i]);
    char b =  asciitolower(word[word.size() - i - 1]);
    
    if (a != b) {
      cout << "não" << endl;
      return 0;
    }
  }

  cout << "sim" << endl;
      return 0;
}
