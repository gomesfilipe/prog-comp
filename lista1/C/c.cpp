#include <iostream>

using namespace std;

int median(int a, int b, int c); 
bool between(int x, int y, int z);

int main() {
    int n, a, b, c;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        cout << "Case " << i + 1 << ": " << median(a, b, c) << endl;
    }

    return 0;
}

int median(int a, int b, int c) {
    if(between(a, b, c)) return a;
    if(between(b, a, c)) return b;
    if(between(c, a, b)) return c;
    return 0;
}

bool between(int x, int y, int z) {
    return (x >= y && x <= z) || (x >= z && x <= y);
}

