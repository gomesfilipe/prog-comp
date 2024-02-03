#include <bits/stdc++.h>

#define endl '\n'
#define mp make_pair
#define pii pair<int, int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    float i, l;
    int n;

    cin >> i >> l >> n;

    float value = i + l * --n;

    printf("%.1f\n", value);

return 0;
}