#include <iostream>
#include <cmath>

using namespace std;

void readBooks(int* books, int n);
int maxBooks(int* books, int t, int n);

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
  int max = 0, time = 0;
  int i = 0; // ceil
  int j = 0; // floor

  for(i = 0; i < n; i++) { // starting from ith book
    time += books[i];
    if(time > t) {
      while(time > t) {
        time -= books[j];
        j++;
      }
    }

    if(i - j + 1 > max) max = i - j + 1;
  }
  return max;
}
