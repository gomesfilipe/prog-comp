#include <iostream>
#include <algorithm>

using namespace std;

int dists[30][30];
char edits[30][30];
string str1, str2;

int minn(int a, int b, int c) {
  if(a <= b && a <= c) return a;
  if(b <= c) return b;
  return c;
}

int editDistance(string& str1, string& str2) {
  int n = str1.size();
  int m = str2.size();
  
  if(n == 0) return m;
  if(m == 0) return n;

  for(int i = 0; i <= n; i++) {
    dists[i][0] = i; // caso base onde ocorrem apenas remoções
    edits[i][0] = 'd';
  }

  for(int j = 0; j <= m; j++) {
    dists[0][j] = j; // caso base onde ocorrem apenas inserções
    edits[0][j] = 'i';
  }

  edits[0][0] = 'x';

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
      
      dists[i][j] = minn(
        dists[i - 1][j] + 1, // delete
        dists[i][j - 1] + 1, // insert
        dists[i - 1][j - 1] + cost // substitute/change
      );
      
      // caso precise descobrir o passo a passo
      if(dists[i][j] == dists[i - 1][j] + 1) {
        edits[i][j] = 'd'; // houve delete na sol. otima

      } else if(dists[i][j] == dists[i][j - 1] + 1) {
        edits[i][j] = 'i'; // houve insert na sol. otima

      } else if(dists[i][j] == dists[i - 1][j - 1] + cost) {
        if(str1[i - 1] == str2[j - 1]) {
          edits[i][j] = 'x';
        } else {
          edits[i][j] = 'c'; // houve substitute/change na sol. otima
        }
      }
    }
  }

  return dists[n][m];
}

void printOperations(string& str1, string& str2) {
  string solution = "E";
  int i = str1.size();
  int j = str2.size();

  while(i >= 0 && j >= 0) {
    string index;
    string c;
    
    if(edits[i][j] == 'd') {
      c.push_back(str1[i - 1]);
      index = to_string(j + 1); // ???
      if(j + 1 < 10) index = "0" + index;

      solution = "D" + c + index + solution;
      i--;

    } else if(edits[i][j] == 'i') {
      c.push_back(str2[j - 1]);
      index = to_string(j);
      if(j < 10) index = "0" + index;

      solution = "I" + c + index + solution;
      j--;

    } else if(edits[i][j] == 'c') {
      c.push_back(str2[j - 1]);
      index = to_string(j);
      if(j < 10) index = "0" + index;
      solution = "C" + c + index + solution;
      i--;
      j--;

    } else { // edits[i][j] == 'x'
      i--;
      j--;
    }
  }

  cout << solution << endl;
  return;
}

void printMatrix(string& str1, string& str2) { // para debugar
  cout << "    ";
  for(int i = 0; i < str1.size(); i++) cout << str2[i] << " ";
  cout << endl;
  
  for(int i = 0; i < str1.size() + 1; i++) {
    if(i > 0) cout << str1[i - 1] << " ";
    else cout << "  ";
    
    for(int j = 0; j < str2.size() + 1; j++) {
      cout << edits[i][j] << " "; // coloca a matriz a ser printada aqui
    }
    cout << endl;
  }
  cout << endl;
} 

int main() {
  while(true) {
    cin >> str1;
    if(str1 == "#") break;
    cin >> str2;

    editDistance(str1, str2);
    printOperations(str1, str2);

    str1.clear();
    str2.clear();
  }

  return 0;
}
