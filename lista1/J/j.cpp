#include <iostream>
#include <vector>
using namespace std;

int squaresFromN(int n);

int main() {
  int n;
  cin >> n;
  vector<int> squares;
  squares.push_back(1);
  
  for(int i = 1; i < n; i++) {
    squares.push_back(squaresFromN(i + 1) + squares.at(i - 1));
  }

  cout << squares.at(n - 1) << endl;
  
  return 0;
}

int squaresFromN(int n) {
  int counter = 0;
  for(int i = 1; i <= n; i++) {
    if(n % i == 0) counter++;
  }

  if(counter % 2 == 1) return (counter - 1) / 2 + 1;
  return counter / 2;
}
