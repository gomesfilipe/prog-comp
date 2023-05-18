#include <iostream>
#include <vector>
using namespace std;

bool solve(int begin, int n, int somaAtual);
void copyArray(bool* a, bool* b, int size);

int X; // sum
int N; // tracks
int S[20];
bool combs[20];

int maxSum = 0;
bool combsMaxSum[20] = {false};

int main() {
  while(true) {
    if(scanf("%d %d ", &X, &N) != 2) break;

    for(int i = 0; i < N; i++) {
      cin >> S[i];
    }

    solve(0, N, 0);

    for(int i = 0; i < N; i++) {
      if(combsMaxSum[i]) {
        cout << S[i] << " ";
      }
    }

    cout << "sum:" << maxSum << endl;
    maxSum = 0;

  }
  
  return 0;
}

bool solve(int begin, int n, int somaAtual) {
	if (begin >= n) {
		if(somaAtual >= maxSum && somaAtual <= X) {
      maxSum = somaAtual;
      copyArray(combsMaxSum, combs, N);
      if(somaAtual == X) {
        return true;
      } else {
        return false;
      }
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

void copyArray(bool* a, bool* b, int size) {
  for(int i = 0; i < size; i++) {
    a[i] = b[i];
  }
  return;
}
