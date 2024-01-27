#include <bits/stdc++.h>

#define endl '\n'
#define mp make_pair
#define pii pair<int, int>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    string original;
    getline(cin, original);

    char ant = original[0];
    int qtd = 0;
    string s = "";
    for (char caractere : original) {
        if(ant == caractere){
            qtd++;
        }
        else{
            s += ant;
            if(qtd > 1){
                s += to_string(qtd);
            }
            ant = caractere;
            qtd = 1;
        }
    }
    s += ant;
    if(qtd > 1){
        s += to_string(qtd);
    }

    if(s.length() < original.length()) cout << s << endl;
    else cout << original << endl;

return 0;
}