#include <bits/stdc++.h>

#define endl '\n'
#define mp make_pair
#define pii pair<int, int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;
    int qtd = 0;
    while(n--){
        int time;
        cin >> time;
        time -= 3;
        if(time > 0){
            qtd += time;
        }
    }
    cout << qtd << endl;

return 0;
}