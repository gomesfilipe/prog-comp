#include <iostream>
#include <cmath>

using namespace std;

void readGarden(int* garden, int n);
int countWateredSections(int* garden, int n, int rainSection);
int isLocalMax(int a, int b, int c);

int main() {
  int n, watered = 0, maxWatered = 0;
  cin >> n;
  
  if(n == 1) {
    cout << "1" << endl;
    return 0;
  }
  
  int garden[n];
  readGarden(garden, n);

  for(int i = 0; i < n; i++) {
    if(i == 0 && garden[i] >= garden[i + 1]) {
      watered = countWateredSections(garden, n, i);

    } else if(i == n - 1 && garden[i] >= garden[i - 1]) {
      watered = countWateredSections(garden, n, i);

    } else if(isLocalMax(garden[i - 1], garden[i], garden[i + 1])) {
      watered = countWateredSections(garden, n, i);
    } else {
      continue;
    }
    
    if(watered > maxWatered) {
      maxWatered = watered;
    }
  }

  cout << maxWatered << endl;
}

void readGarden(int* garden, int n) {
  for(int i = 0; i < n; i++) {
    cin >> garden[i];
  }
  return;
}

int countWateredSections(int* garden, int n, int rainSection) {
  int counter = 1;

  for(int i = rainSection - 1; i >= 0 && garden[i] <= garden[i + 1]; i--) {
    counter++;
  }

  for(int i = rainSection + 1; i <= n - 1 && garden[i] <= garden[i - 1]; i++) {
    counter++;
  }

  return counter;
}

int isLocalMax(int a, int b, int c) {
  return a <= b && b > c;
}
