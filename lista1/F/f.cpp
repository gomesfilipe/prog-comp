#include <iostream>
using namespace std;

int main() {
    int soma = 0, x, n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x;
        soma += x;
    }

    if(soma > 0) {
        cout << ":)" << endl;
    } else if(soma < 0) {
        cout << ":(" << endl;
    } else {
        cout << ":|" << endl;
    }

    return 0;
}
