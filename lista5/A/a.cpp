#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetSum(vector<int>& bars, int nBars, int sizeWanted);
void readVector(vector<int>& v, int size);
bool solve(int begin, int n, int somaAtual, vector<int>& bars, vector<bool>& combs, int X);

int main() {
    int t, sizeWanted, nBars;
    vector<int> bars;
    cin >> t;
    for(int i = 0; i < t; i++) {
      cin >> sizeWanted >> nBars;
      readVector(bars, nBars);
      subsetSum(bars, nBars, sizeWanted);
      bars.clear();
    }

    return 0;
}

void subsetSum(vector<int>& bars, int nBars, int sizeWanted) {
    vector<bool> combs(nBars, false);
    
    if(solve(0, nBars, 0, bars, combs, sizeWanted)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }

    return;
}

void readVector(vector<int>& v, int size) {
  int x;
  for(int i = 0; i < size; i++) {
    cin >> x;
    v.push_back(x);
  }

  return;
}

bool solve(int begin, int n, int somaAtual, vector<int>& bars, vector<bool>& combs, int X) {
	if (begin >= n) {
		if (somaAtual == X)
      return true;
    return false;
  } else if (somaAtual > X) {
    return false;   
  } else {
		combs[begin] = false;
		bool without = solve(begin + 1, n, somaAtual, bars, combs, X);
		combs[begin] = true;
		bool with = solve(begin + 1, n, somaAtual + bars[begin], bars, combs, X);
      return with or without;
    }
}
