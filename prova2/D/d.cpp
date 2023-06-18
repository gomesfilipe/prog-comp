#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int t;
  cin >> t;

  for(int i = 0; i < t; i++) {
    int stick, diamond;
    cin >> stick >> diamond;

    int maior = max(stick, diamond);
    int menor = min(stick, diamond);

    if(maior > 2 * menor) {
      cout << menor << endl;  
    } else {
      cout << (stick + diamond) / 3 << endl;
    }
  }
  return 0;
}
