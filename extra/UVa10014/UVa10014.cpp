#include <iostream>

using namespace std;

int main() {
  unsigned long int t, n;

  cin >> t;

  for(int i = 0; i < t; i++) {
    cout << "Case " << i + 1 << ": ";
    cin >> n;
    unsigned long int num = n * (n - 1);

    if(num % 4 == 0) {
      cout << num / 4 << endl;
    } else {
      cout << num / 2 << "/" << 2 << endl;
    }
  }

  return 0;
}
