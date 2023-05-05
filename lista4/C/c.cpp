#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

int maxTwoValues(int a, int b) {
  return a > b ? a : b;
}

int maxThreeValues(int a, int b, int c) {
  if(a >= b && a >= c) return a; 
  if(b >= a && b >= c) return b; 
  if(c >= a && c >= b) return c;
  return 0; 
}

//# Método Recursivo
//# Constrói uma SegTree 'T' a partir de um array 'A'
//# O primeiro elemento de 'A' está em 'start'
//# O último elemenot de 'A' está em 'end'
//# O nó atual da árvore sendo analisado é 'node'
void buildRec(int* T, int* A, int node, int start, int end) {
    if(start == end) {
        //# Folha representa um elemento único 
        T[node] = A[start];
    } else {
        int mid = (start + end) / 2;
        //# Chamada recursiva para filho à esquerda 
        buildRec(T, A, 2 * node, start, mid);
        //# Chamada recursiva para filho à direita
        buildRec(T, A, 2 * node + 1, mid+1, end);
        //# Nó interno tem a SOMA dos dois filhos 
        T[node] = maxTwoValues(T[2 * node], T[2 * node + 1]);        //# <======= IMPORTANTE
    }
}
//# Interface para a construção da árvore
//# 'T' é o vetor que armazenará a árvore
//# 'A' é o vetor com os dados originais
//# 'n' é o número de elemento em 'A'. 'T' deve ter tamanho '2n'
//# Complexidade de tempo: O(n)
//# Complexidade de espaço: O(n)
void build(int *T, int *A, int n) {
    buildRec(T, A, 1, 0, n-1); //# A raíz tem nó 1 e representa o segmento A[0, ..., n-1]
}

//# Função recursiva pela busca da soma de A[l, ..., r]
//# 'T' é a SegTree
//# 'node' é o nó atual da SegTree sendo inspecionado
//# 'start' é o início do intervalo representado em 'node'
//# 'end' é o fim do intervalo representado em 'node'
//# 'l' é o limite inferior da busca
//# 'r' é o limite superior da busca
int queryRec(int *T, int node, int start, int end, int l, int r) {
    if(r < start or end < l) {
        //# [start, end] está fora de [l, r] -- não há interseção
        return 0;                                       //# <======= IMPORTANTE
    }
    if(l <= start and end <= r){
        //# [start, end] está contido em [l, r] 
        return T[node];
    }
    //# [start, end] e [l, r] têm interseção 
    int mid = (start + end) / 2;
    int p1 = queryRec(T, 2 * node, start, mid, l, r);
    int p2 = queryRec(T, 2 * node + 1, mid + 1, end, l, r);
    return maxTwoValues(p1, p2);                                   //# <======= IMPORTANTE
}

//# Interface para a busca: Soma dos elementos A[l, ..., r]
//# 'T' é a SegTree
//# 'n' é o número de elementos no vetor 'A'
//# 'l' limite inferior da busca
//# 'r' limite superior da busca
int query(int* T, int n, int l, int r) { //#Soma(A[l, ..., r])
    return queryRec(T, 1, 0, n-1, l, r);
}

void readVector(int *v, int n) {
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    return;
}

void buildFrequencyArray(int* A, int n, int* freq) {
  unordered_map<int, int> count;

  for(int i = 0; i < n; i++) {
    count[A[i]]++;
  }

  for(int i = 0; i < n; i++) {
    freq[i] = count[A[i]];
  }

  return;
}

int maxOcurrenceInRange(int* A, int* T, int* freq, int n, int l, int r) {
  if(A[l] == A[r]) {
    return r - l + 1;
  }

  int sameLeftMost = 0, sameRightMost = 0;

  while(l >= 0 && l < r && A[l] == A[l + 1]) {
    l++;
    sameLeftMost++;
  }

  l++;
  sameLeftMost++;

  while(r > l && r <= n - 1 && A[r] == A[r - 1]) {
    r--;
    sameRightMost++;
  }

  r--;
  sameRightMost++;
  return maxThreeValues(sameLeftMost, sameRightMost, query(T, n, l, r));
}

void printVector(int *v, int n) {
    cout << "##########" << endl;
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl << "##########" << endl;

    return;
}

void executeTestCase(int n, int q) {
  int A[n], l, r;
  int T[4 * n] = {0};
  int freq[n];

  readVector(A, n);
  buildFrequencyArray(A, n, freq);
  build(T, freq, n);

  for(int i = 0; i < q; i++) {
    cin >> l >> r;
    cout << maxOcurrenceInRange(A, T, freq, n, l - 1, r - 1) << endl;
  }

  return;
}

int main() {
  int n, q;
  
  while(true) {
    cin >> n;
    if(n == 0) break;
    cin >> q;
    executeTestCase(n, q);
  }

  return 0;
}
