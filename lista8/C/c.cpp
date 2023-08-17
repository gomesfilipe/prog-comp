// BOT-TOP, calcula o tamanho da LCS e descobre a própria LCS

#include <iostream>
#include <algorithm>

using namespace std;

int table[3001][3001];
int subseq[3001][3001];

string str1, str2;

int LCS(string& str1, string& str2) {
  int n = str1.size();
  int m = str2.size();
  
  for(int i = 0; i <= n; i++) {
    table[i][0] = 0; // caso base
  }

  for(int j = 0; j <= m; j++) {
    table[0][j] = 0; // caso base
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(str1[i - 1] == str2[j - 1]) {
        table[i][j] = 1 + table[i - 1][j - 1];
        subseq[i][j] = 1;
      
      } else if(table[i - 1][j] >= table[i][j - 1]) {
        table[i][j] = table[i - 1][j];
        subseq[i][j] = 2;
      
      } else {
        table[i][j] = table[i][j - 1];
        subseq[i][j] = 3;
      }
    }
  }

  return table[n][m];
}

void printLCS(string& str1, int i, int j) {
  if(i == 0 || j == 0) return;

  if(subseq[i][j] == 1) {
    printLCS(str1, i - 1, j - 1);
    cout << str1[i - 1];
  
  } else if(subseq[i][j] == 2) {
    printLCS(str1, i - 1, j);

  } else {
    printLCS(str1, i, j - 1);
  }

  return;
}

void printLCSIterative(string& str1, string& str2) {
  string solution = "";
  int i = str1.size();
  int j = str2.size();

  while(i > 0 && j > 0) {
    if(table[i][j] > table[i - 1][j] && table[i][j] > table[i][j - 1]) {
      solution = str1[i - 1] + solution;
      i--;
      j--;
    
    } else if(table[i][j - 1] > table[i - 1][j]) {
      j--;
    } else {
      i--;
    }

  }
  cout << solution;
  return;
}

int main() {
  // int t;
  // cin >> t;

  // for(int i = 0; i < t; i++) {
  //   cin >> str1;
  //   cin >> str2;

  //   int n = str1.size();
  //   int m = str2.size();

  //   cout << LCS(str1, str2) << endl;
  //   printLCS(str1, n, m);
  //   cout << endl;
  //   str1.clear();
  //   str2.clear();
  // }

  cin >> str1;
  cin >> str2;

  int n = str1.size();
  int m = str2.size();

  LCS(str1, str2);
  // printLCS(str1, n, m);
  printLCSIterative(str1, str2);
  cout << endl;

  return 0;
}
