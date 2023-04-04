#include <iostream>

using namespace std;

void printQuadrant(int x, int y);

int main() {
    int n, x, y, a, b;
    cin >> n;

    if(n == 0) return 0;

    cin >> a >> b;
    
    while(true) {
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            printQuadrant(x - a, y - b);
        }
        cin >> n;
        if(n == 0) break;
        cin >> a >> b;
    }

    return 0;
}

void printQuadrant(int x, int y) {
    if(x > 0 && y > 0) {
        cout << "NE" << endl;
    } else if(x > 0 && y < 0) {
        cout << "SE" << endl;
    } else if(x < 0 && y > 0) {
        cout << "NO" << endl;
    } else if(x < 0 && y < 0) {
        cout << "SO" << endl;
    } else {
        cout << "divisa" << endl;
    }

    return;
}