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
    int all_num[n];
    for(int i = 0; i < n; i++){
        cin >> all_num[i];
    }

    vector<int> imp;
    vector<int> par;
    for(int i = 0; i < n; i++){
        if(all_num[i] % 2 == 0){
            par.push_back(all_num[i]);
        }
        else{
            imp.push_back(all_num[i]);
        }
    }

    sort(imp.begin(), imp.end());
    sort(par.begin(), par.end());

    for(int a : imp){
        cout << a << " ";
    }
    for(int a : par){
        cout << a << " ";
    }

    

return 0;
}
