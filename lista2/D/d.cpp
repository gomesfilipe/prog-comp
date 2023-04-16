#include <iostream>
#include <vector>
using namespace std;

void decimalToBits(int d);
void invertBytes(int startIndex1, int startIndex2);
int c2ToDecimal();

vector<int> v(32);

int main() {
  int n;
  while(true) {
    if(!(cin >> n)) break;
    decimalToBits(n);

    for(int i = 0; i < 16; i += 8) {
      invertBytes(i, 24 - i);
    }

    cout << n << " converts to " <<  c2ToDecimal() << endl;
  }

  return 0;
}

void decimalToBits(int d) {
  for(int i = 0; i < 32; i++) {
    if((d >> (31 - i)) % 2 == 0) {
      v[i] = 0;
    } else {
      v[i] = 1;
    }
  }

  return;
}

void invertBytes(int startIndex1, int startIndex2) {
  int tmp;
  for(int i = 0; i < 8; i++) {
    tmp = v[startIndex1 + i];
    v[startIndex1 + i] = v[startIndex2 + i];
    v[startIndex2 + i] = tmp;
  }
  return;
}

int c2ToDecimal() {
  int sum = 0;
  for(int i = 1; i < 32; i++) {
    sum += ((1 << (31 - i)) * v[i]);
  }

  if(v[0] == 0) {
    return sum;
  } else {
    return sum - 2147483648;
  }
}
