#include <iostream>
#include <vector>
#include <set>
using namespace std;

int X;
int N;
int S[12];

bool combs[12];

bool solve(int begin, int n, int somaAtual, set<vector<int>>& sums) {
	if (begin >= n) {
    if (somaAtual == X){
      vector<int> sum;
      for(int i = 0; i < N; i++){
        if(combs[i]){
          sum.push_back(S[i]);
        }
      }
      sums.insert(sum);
      return true;
    }
      return false;
    } else if (somaAtual > X) {
      return false;   
    } else {
      combs[begin] = false;
      bool without = solve(begin + 1, n, somaAtual, sums);
      combs[begin] = true;
      bool with = solve(begin + 1, n, somaAtual + S[begin], sums);
      return with or without;
	}
}

int main() {
  while(true){
    cin >> X >> N;
    if(N == 0) break;
    
    for (int i = 0; i < N; i++){
      cin >> S[i];
    }

    cout << "Sums of " << X << ":" << endl;

    set<vector<int>> sums;
    bool aux = false;
    if(solve(0, N, 0, sums)){
      for (auto itr = sums.rbegin(); itr != sums.rend(); itr++){
        bool aux = false;
        for(auto num : *itr){
          if(aux){
            cout << "+";
          }
          cout << num;
          aux = true;
        }
        cout << endl;
      }
    }
    else{
        cout << "NONE" << endl;
    }
  }

  return 0;
}
