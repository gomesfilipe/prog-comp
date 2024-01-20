#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isVogal(char in) {
    if (in == 'A' || in == 'E' || in == 'I' || in == 'O' || in == 'U' || in == 'a' || in == 'e' || in == 'i' || in == 'o' || in == 'u') {
      return true;
    }
   return false;
}

int main() {
  string word;
  getline(cin, word);
  
  int count = 0;

  for (int i = 0; i < word.size(); i++) {
    if (isVogal(word[i])) {
      count++;
    }
  }

  cout << count << endl;
  return 0;
}
