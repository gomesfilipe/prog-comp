#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a;
        cin >> b;
        
        if(a > b) {
            cout << ">" << endl;
        } else if (a < b) {
            cout << "<" << endl;
        } else {
            cout << "=" << endl;
        }
    }
    return 0;
}
