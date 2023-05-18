#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool solve(int begin, int n, int somaAtual);
void buildSum(vector<int>& subset);
void printSum(const vector<int>& subset);

int X;
int N;
int S[12];
bool combs[12];
set<vector<int>> sums;

int main() {
  while(true) {
    cin >> X >> N;
    if(N == 0) break;

    for(int i = 0; i < N; i++) {
      cin >> S[i];
    }

    solve(0, N, 0);

    cout << "Sums of " << X << ":" << endl;
    if(sums.empty()) {
      cout << "NONE" << endl;
    } else {
      // for(const auto& sum : sums) {
      for(auto it = sums.rbegin(); it != sums.rend(); it++) {
        printSum(*it);
      }
    }

    sums.clear();
  }
  return 0;
}

bool solve(int begin, int n, int somaAtual) {
	if (begin >= n) {
		if (somaAtual == X) {
      vector<int> subset;
      buildSum(subset);
      sums.insert(subset);
      return true;
    }
    return false;
  } else if (somaAtual > X) {
    return false;   
  } else {
		combs[begin] = false;
		bool without = solve(begin + 1, n, somaAtual);
		combs[begin] = true;
		bool with = solve(begin + 1, n, somaAtual + S[begin]);
    return with or without;
	}
}

void buildSum(vector<int>& subset) {
  for(int i = 0; i < N; i++) {
    if(combs[i]) subset.push_back(S[i]);
  }
  return;
}

void printSum(const vector<int>& subset) {
  for(int i = 0; i < subset.size(); i++) {
    if(i > 0) cout << "+";
    cout << subset[i];
  }
  cout << endl;
  return;
}
