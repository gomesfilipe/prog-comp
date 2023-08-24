#include <iostream>

using namespace std;

int main() {
  int t, n;
  double a, b, sum = 0.0;

  cin >> t;

  for(int i = 0; i < t; i++, sum = 0.0) {
    cin >> n;
    cin >> a;
    cin >> b;

    for(int j = 1; j <= n; j++) {
      double c;
      cin >> c;
      sum += c * (n - j + 1);
    }

    printf("%.2lf\n", (b + n * a - 2.0 * sum) / (n + 1));

    if(i != t - 1) cout << endl;
  }

  return 0;
}
