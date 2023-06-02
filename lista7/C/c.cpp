#include <iostream>
using namespace std;

// se usar cin/cout dá time limit
int main() {
  ios::sync_with_stdio(false);
  int n;
  int a, g, diff = 0;
  scanf("%d", &n);
  
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &a, &g);
    
    if(diff + a <= 500) {
      diff += a;
      printf("A");
      
    } else {
      diff -= g;
      printf("G");
    }
  }
  printf("\n");
}
