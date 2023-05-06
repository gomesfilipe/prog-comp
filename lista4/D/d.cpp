#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

pair<int, int> maxPair(pair<int, int> p1, pair<int, int> p2) {
  priority_queue<int> pq;
  pq.push(p1.first);
  pq.push(p1.second);
  pq.push(p2.first);
  pq.push(p2.second);

  int greatest = pq.top();
  pq.pop();
  int second_greatest = pq.top();
  return make_pair(greatest, second_greatest);
}

//# Método Recursivo
//# Constrói uma SegTree 'T' a partir de um array 'A'
//# O primeiro elemento de 'A' está em 'start'
//# O último elemenot de 'A' está em 'end'
//# O nó atual da árvore sendo analisado é 'node'
void buildRec(pair<int, int>* T, int* A, int node, int start, int end) {
    if(start == end) {
        //# Folha representa um elemento único 
        // T[node] = { A[start], 0 };
        T[node] = make_pair(A[start], 0);
    } else {
        int mid = (start + end) / 2;
        //# Chamada recursiva para filho à esquerda 
        buildRec(T, A, 2 * node, start, mid);
        //# Chamada recursiva para filho à direita
        buildRec(T, A, 2 * node + 1, mid+1, end);
        //# Nó interno tem a SOMA dos dois filhos 
        T[node] = maxPair(T[2 * node], T[2 * node + 1]);        //# <======= IMPORTANTE
    }
}
//# Interface para a construção da árvore
//# 'T' é o vetor que armazenará a árvore
//# 'A' é o vetor com os dados originais
//# 'n' é o número de elemento em 'A'. 'T' deve ter tamanho '2n'
//# Complexidade de tempo: O(n)
//# Complexidade de espaço: O(n)
void build(pair<int, int>* T, int *A, int n) {
    buildRec(T, A, 1, 0, n-1); //# A raíz tem nó 1 e representa o segmento A[0, ..., n-1]
}

//# Função recursiva pela busca da soma de A[l, ..., r]
//# 'T' é a SegTree
//# 'node' é o nó atual da SegTree sendo inspecionado
//# 'start' é o início do intervalo representado em 'node'
//# 'end' é o fim do intervalo representado em 'node'
//# 'l' é o limite inferior da busca
//# 'r' é o limite superior da busca
pair<int, int> queryRec(pair<int, int>* T, int node, int start, int end, int l, int r) {
    if(r < start or end < l) {
        //# [start, end] está fora de [l, r] -- não há interseção
        return make_pair(0, 0);;                                       //# <======= IMPORTANTE
    }
    if(l <= start and end <= r){
        //# [start, end] está contido em [l, r] 
        return T[node];
    }
    //# [start, end] e [l, r] têm interseção 
    int mid = (start + end) / 2;
    pair<int, int> p1 = queryRec(T, 2 * node, start, mid, l, r);
    pair<int, int> p2 = queryRec(T, 2 * node + 1, mid + 1, end, l, r);
    return maxPair(p1, p2);                                   //# <======= IMPORTANTE
}
//# Interface para a busca: Soma dos elementos A[l, ..., r]
//# 'T' é a SegTree
//# 'n' é o número de elementos no vetor 'A'
//# 'l' limite inferior da busca
//# 'r' limite superior da busca
pair<int, int> query(pair<int, int>* T, int n, int l, int r) { //#Soma(A[l, ..., r])
    return queryRec(T, 1, 0, n-1, l, r);
}

//# Função Recursiva para atualizar A[idx], fazendo A[idx] += val
//# 'T' é a SegTree
//# 'A' é o vetor original com os elementos
//# 'node' é o nó atual da SegTree sendo inspecionado
//# 'start' é o início do intervalo representado por 'node' 
//# 'end' é o fim do intervalo representado por 'node' 
//# 'idx' é o índice do elemento a ser atualizado
//# 'val' é o valor a ser somado a A[idx]
void updateRec(pair<int, int>* T, int* A, int node, int start, int end, int idx, int val) {
    if(start == end) {
        //# Nó folha, atualiza A e T
        A[idx] += val;
        T[node].first += val;
    } else {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid) {
            //# idx está no filho à esquerda 
            updateRec(T, A, 2 * node, start, mid, idx, val);
        } else {
            //# idx está no filho à direita 
            updateRec(T, A, 2 * node + 1, mid + 1, end, idx, val);
        }
        //# Faz atualização do nó pai 
        // T[node] = T[2 * node] + T[2 * node + 1];   
        T[node] = maxPair(T[2 * node], T[2 * node + 1]);     //# <======= IMPORTANTE
    }
}
//# Interface para atualizar A[idx], fazendo A[idx] += val
//# 'T' é a SegTree
//# 'A' é o vetor original com os elementos
//# 'n' é o tamanho de 'A'
//# 'idx' é o índice do elemento a ser atualizado
//# 'val' é o valor a ser somado a A[idx]
void update(pair<int, int>* T, int *A, int n, int idx, int val) { //# A[idx] = A[idx] + val
    updateRec(T, A, 1, 0, n - 1, idx, val);
}

void readVector(int *v, int n) {
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    return;
}

int main() {
  int n, q, a, b;
  cin >> n;
  int A[n];
  pair<int, int> T[4 * n];
  char command;

  readVector(A, n);
  build(T, A, n);

  cin >> q;

  for(int i = 0; i < q; i++) {
    cin >> command >> a >> b;
    if(command == 'Q') { // Query
      pair<int, int> result = query(T, n, a - 1, b - 1);
      cout << result.first + result.second << endl;
    } else { // Update
      update(T, A, n, a - 1, b - A[a - 1]);
    }
  }

  return 0;
}
