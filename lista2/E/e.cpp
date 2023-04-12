#include <iostream>
#include <vector>
using namespace std;

void throwCards(int n);

int main() {
  int n;
  
  while(true) {
    cin >> n;
    if(n == 0) break;
    throwCards(n);
  }

  return 0;
}

void throwCards(int n) {
  int top = 0, bot = n;
  vector<int> v(100, -1);

  for(int i = 0; i < n; i++) {
    v[i] = i + 1;
  }

  cout << "Discarded cards:";
  for(int i = 0; top != bot - 1; i++) {
    if(i % 2 == 0) {
      if(i == 0) {
        cout << " " << v[top];
      } else {
        cout << ", " << v[top];
      }

      top++;
    } else {
      v[bot] = v[top];
      bot++;
      top++;
    }

  }
  cout << endl << "Remaining card: " << v[top] << endl;
  return;
}
