#include <iostream>
#include <cmath>

using namespace std;

void readInput(int n);
double f(double T, int n);
double ternarySearch(double K, int n);

int D[100005];
int S[100005];

int main() {
  ios::sync_with_stdio(false);
  int n;
  double k;
  scanf("%d %lf", &n, &k);
  readInput(n);

  printf("%.6f", ternarySearch(k, n));
  return 0;
}

void readInput(int n) {
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &S[i], &D[i]);
  }
  return;
}

double f(double T, int n) {
  double min = D[0] * 1.0 + S[0] * T;
  double max = D[0] * 1.0 + S[0] * T;
  
  for(int i = 1; i < n; i++) {
    double tmp = D[i] * 1.0 + S[i] * T;
    
    if(tmp > max) {
      max = tmp;

    } else if(tmp < min){
      min = tmp;
    }
  }

  return max - min;
}

double ternarySearch(double K, int n) {
  double left = 0;
  double right = K;
  double m1, m2, f1, f2;

  for(int i = 0; i < 200; i++) {
    m1 = left + (right - left) / 3.0;
    m2 = right - (right - left) / 3.0;

    f1 = f(m1, n);
    f2 = f(m2, n);

    if(f1 > f2) {
      left = m1;
    } else {
      right = m2;
    }
  }

  double fl = f(left, n);
  double fr = f(right, n);
  
  if(fl <= fr) {
    return fl;
  } else {
    return fr;
  }
}
