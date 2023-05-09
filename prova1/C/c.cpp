#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isJolly(int n) {
  int a, b, diff;
  if(n == 1) {
    scanf("%d", &b);
    return true;
  }
    
  vector<bool> diffFound(n - 1 , false);
    
  scanf("%d", &a);

  for(int i = 0; i < n - 1; i++) {
    scanf("%d", &b);
    diff = abs(a - b);

    if(diff < 1 || diff > n - 1 || diffFound[diff - 1]) {
      for(int j = i + 1; j < n -1 ; j++) {
        scanf("%d", &b);
      }
      return false;
    } else {
      diffFound[diff - 1] = true;
    }
      a = b;
  }

  return true;
} 

int main() {
  int n;

  while(true) {
    if(scanf("%d", &n) != 1) break;

    if(isJolly(n)) {
      cout << "Jolly" << endl;
    } else {
      cout << "Not jolly" << endl;
    }
  }

  return 0;
}
