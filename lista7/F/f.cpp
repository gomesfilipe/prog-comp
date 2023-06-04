#include <iostream>
using namespace std;

int maxx(int a, int b);

int main() {
  int t, n, d;
  char trash;
  scanf("%d", &t);

  for(int j = 0; j < t; j++) {
    scanf("%d %d\n", &n, &d);

    int dists[n + 2];
    bool visited[n + 2];
    char type[n + 2];


    for(int i = 1; i < n + 1; i++) {
      scanf("%c%c%d ", &type[i], &trash, &dists[i]);
      visited[i] = false;
      // printf("trash: (%c)\n", trash);
      // printf("(%c)(%d)(%d)\n", type[i], dists[i], visited[i]);
    }


    type[0] = 'B';
    visited[0] = false;
    dists[0] = 0;
    int maxLeap = dists[0];

    type[n + 1] = 'B';
    visited[n + 1] = false;
    dists[n + 1] = d;

    // ida
    for(int i = 0; i < n + 1; i++) {
      // printf("visitando ida: [%d]\n", i);
      // printf("visitou %d ida\n", dists[i]);
      visited[i] = true;
      if(i == n) {
        break;
      }

      if(type[i + 1] == 'B') { // se o próximo é big
        maxLeap = maxx(maxLeap, dists[i + 1] - dists[i]);
      } else { // se o próximo é small
        maxLeap = maxx(maxLeap, dists[i + 2] - dists[i]);
        i++;
      } 
    }

    // volta
    for(int i = n + 1; i > 0; i--) {
      // printf("visitando volta: [%d]\n", i);
      visited[i] = true;
      
      // printf("visitou %d volta\n", i);
      if(visited[i - 1] == false || type[i - 1] == 'B') {
        // printf("maxleap [%d] diff [%d - %d]\n", maxLeap, i, i - 2);
        maxLeap = maxx(maxLeap, dists[i] - dists[i - 1]);
      } else {
        maxLeap = maxx(maxLeap, dists[i] - dists[i - 2]);
        i--;
      }
    }

    printf("Case %d: %d\n", j + 1, maxLeap);
  }
}

int maxx(int a, int b) {
  return a > b ? a : b;
}
