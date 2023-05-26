#include <iostream>
#include <cmath>

using namespace std;

bool isPalindrome(string& word, int i, int j);

int main(){
	// ios::sync_with_stdio(false);
	string word;
  cin >> word;

  for(int k = word.size(); k >= 2; k--) {
    for(int i = 0, j = k - 1; i < word.size() - j; i++) {
      if(!isPalindrome(word, i, j)) {
        cout << j - i + 1 << endl;
        return 0;
      }
    }
  }

  cout << 0 << endl;
	return 0;

}

bool isPalindrome(string& word, int i, int j) {
  for(int k = i; k <= i + (j - i) / 2; k++) {
    if(word[k] != word[j - k]) {
      return false;
    }
  }

  return true;
}
