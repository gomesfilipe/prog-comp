#include <iostream>
#include <cmath>

using namespace std;

void readSquare();
void thereIsSquare();

char square[4][4];

int main(){
	readSquare();
  thereIsSquare();
	return 0;
}

void readSquare() {
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      cin >> square[i][j];
    }
  }
  return;
}

void thereIsSquare() {
  int blacks, whites;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      blacks = 0;
      whites = 0;

      square[i    ][j    ] == '#' ? blacks++ : whites++;
      square[i    ][j + 1] == '#' ? blacks++ : whites++;
      square[i + 1][j    ] == '#' ? blacks++ : whites++;
      square[i + 1][j + 1] == '#' ? blacks++ : whites++;
      
      if(blacks == 3 || whites == 3 || blacks == 4 || whites == 4) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
  return;
}
