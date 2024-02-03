#include <bits/stdc++.h>

#define endl '\n'
#define mp make_pair
#define pii pair<int, int>

using namespace std;

bool isCapicua(int n){
    string s = to_string(n);

    int init = 0, end = s.size() -1;
    // cout << s << endl;

    while(init < end){
        if(s[init] != s[end]) return false;
        init++;
        end--;
    }
    return true;
}

int sumNum(int n){
    int invertido = 0;

    while (n > 0) {
        int digito = n % 10; // Extrai o último dígito
        invertido = invertido * 10 + digito; // Adiciona o dígito invertido ao novo número
        n /= 10; // Remove o último dígito do número original
    }
    return n + invertido;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;

    for(int i = 0; i < 4; i++){
        if(isCapicua(n)) break;
        n += sumNum(n);
    }

    if(isCapicua(n)) cout << n << endl;
    else cout << 0 << endl;


return 0;
}