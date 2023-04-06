#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;

int main() {
  int t, n, length, element, bit0 = 0, bit1 = 0, answer = 0;
  cin >> t;
  
  for(int i = 0; i < t; i++) {
    cin >> n;
    for(int j = 0; j < n; j++) {
      cin >> element;
      v.push_back(element);
    }

    for(int k = 0; k < 8; k++) {
      for(auto& x : v) {
        if(x % 2 == 0) {
          bit0++;
        } else {
          bit1++;
        }
        x = x >> 1;
      }

      if(bit0 % 2 == 1 && bit1 % 2 == 1) {
        answer = -1;
        break;
      } else if(bit1 % 2 == 1) {
        answer += pow(2, k);
      }

      bit0 = 0;
      bit1 = 0;
    }
    cout << answer << endl;
    bit0 = 0;
    bit1 = 0;
    answer = 0;
    v.clear();
  }

  return 0;
}
