#include <bits/stdc++.h>

#define endl '\n'
#define mp make_pair
#define pii pair<int, int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    long double v, x;
    int i;

    scanf("%Lf", &v);
    scanf("%d", &i);

    if (i <= 5) {
      x = (long double) 0.5 * v;
    } else if(i > 5 && i < 18) {
      x = (long double) 0.95 * v;
    } else if(i >= 18 && i < 60) {
      x = (long double) 1.1 * v;
    } else {
      x = (long double) 0.85 * v;
    }

    printf("%.2Lf\n", x);
    printf("%Lf\n", x);
    printf("%Lf", round(x * 100) / 100);

return 0;
}