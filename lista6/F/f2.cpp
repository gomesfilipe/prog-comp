#include <iostream>
#include <cmath>

using namespace std;

void readBooks(int* books, int n);
int maxBooks(int* books, int t, int n);
int sumBooks(int* books, int n);

int main(){
  ios::sync_with_stdio(false);
  int n, t;
  cin >> n >> t;
  int books[n];
  readBooks(books, n);
  cout << maxBooks(books, t, n) << endl;
	return 0;
}

void readBooks(int* books, int n) {
  for(int i = 0; i < n; i++) {
    cin >> books[i];
  }
  return;
}

int maxBooks(int* books, int t, int n) {
  int segmentSum;
  int sum = sumBooks(books, n);
  if(sum <= t) return n;

  for(int k = n - 1; k >= 1; k--) { // size candidates
    sum -= books[k];
    for(int i = 0, j = k - 1; j < n; i++, j++) {
      if(i == 0) {
        segmentSum = sum;
      } else {
        segmentSum = segmentSum - books[i - 1] + books[j];
      }

      if(segmentSum <= t) return k;
    }
  }
  return 0;
}

int sumBooks(int* books, int n) {
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += books[i];
  }
  return sum;
}
