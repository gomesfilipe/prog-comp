#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void checkMatrix(int n);
int sumRow(int n, int row);
int sumColumn(int n, int column);

int m[100][100];

int main() {
  int n;
  while ((true)) {
    cin >> n;
    if(n == 0) break;
    checkMatrix(n);
  }
  return 0;
}

void checkMatrix(int n) {
  int row = -1;
  int column = -1;

  int parColumns = 0;
  int imparColumns = 0;
  int parRows = 0;
  int imparRows = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> m[i][j];
    }
  }

  // somando colunas
  for(int j = 0; j < n; j++) {
    if(sumColumn(n, j) % 2 == 0) {
      parColumns++;
    } else {
      imparColumns++;
      if(column != -1) {
        cout << "Corrupt" << endl;
        return;
      } else {
        column = j;
      }
    }
  }

  // somando linhas
  for(int i = 0; i < n; i++) {
    if(sumRow(n, i) % 2 == 0) {
      parRows++;
    } else {
      imparRows++;
      if(row != -1) {
        cout << "Corrupt" << endl;
        return;
      } else {
        row = i;
      }
    }
  }

  if(imparRows == 0 && imparRows == 0) {
    cout << "OK" << endl;
  } else if(row == -1 || column == -1) {
    cout << "Corrupt" << endl;
  } else {
    cout << "Change bit (" << row + 1 << "," << column + 1 << ")" << endl;
  }
  return;
}

int sumRow(int n, int row) {
  int sum = 0;
  for(int j = 0; j < n; j++) {
    sum += m[row][j];
  }
  return sum;
}

int sumColumn(int n, int column) {
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += m[i][column];
  }
  return sum;
}
