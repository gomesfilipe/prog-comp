#include <iostream>

using namespace std;

int image[25][25];
bool visited[25][25];

void inicImage(int n) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%1d", &image[i][j]);
      visited[i][j] = false;
    }
  }

  return;
}

bool validPosition(int i, int j, int n) {
  return i >= 0 && i < n && j >= 0 && j < n;
}

void dfs(int i, int j, int n) {
  if (!validPosition(i, j, n) || visited[i][j] || image[i][j] == 0) return;

  visited[i][j] = true;

  dfs(i - 1, j - 1, n);
  dfs(i - 1, j + 1, n);
  dfs(i - 1, j, n);

  dfs(i, j - 1, n);
  dfs(i, j + 1, n);

  dfs(i + 1, j - 1, n);
  dfs(i + 1, j + 1, n);
  dfs(i + 1, j, n);

  return;
}

int countWarEagles(int n) {
  int counter = 0;
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(!visited[i][j] && image[i][j] == 1) {
        dfs(i, j, n);
        counter++;
      }
    }
  }

  return counter;
}

int main() {
  int n, i = 1;
  while(scanf("%d", &n) == 1) {
    inicImage(n);
    printf("Image number %d contains %d war eagles.\n", i++, countWarEagles(n));
  }

  return 0;
}
