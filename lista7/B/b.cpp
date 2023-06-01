#include<iostream>
#include<climits>

using namespace std;

pair<int, int> maxPair(pair<int, int> p1, pair<int, int> p2) {
  if(p1.first > p2.first) {
    return p1;
  } else if(p1.first < p2.first) {
    return p2;
  } else if(p1.second <= p2.second) {
    return p1;
  } else if(p1.second > p2.second) {
    return p2;
  }

  return make_pair(INT_MIN, -1);
}

void buildRec(pair<int, int>* T, int*A, int node, int start, int end) {
    if(start == end) {
        T[node] = make_pair(A[start], start);
    } else {
        int mid = (start + end) / 2;
        buildRec(T, A, 2 * node, start, mid);
        buildRec(T, A, 2 * node + 1, mid+1, end);
        T[node] = maxPair(T[2 * node], T[2 * node + 1]);    //# <======= IMPORTANTE
    }
}

void build(pair<int, int>* T, int *A, int n) {
    buildRec(T, A, 1, 0, n-1);
}

pair<int, int> queryRec(pair<int, int>* T, int node, int start, int end, int l, int r) {
    if(r < start or end < l) {
        return make_pair(INT_MIN, -1);                                 //# <======= IMPORTANTE
    }
    if(l <= start and end <= r){
        return T[node];
    }
    int mid = (start + end) / 2;
    pair<int, int> p1 = queryRec(T, 2 * node, start, mid, l, r);
    pair<int, int> p2 = queryRec(T, 2 * node + 1, mid + 1, end, l, r);
    return maxPair(p1, p2);                                 //# <======= IMPORTANTE
}

pair<int, int> query(pair<int, int>* T, int n, int l, int r) {
    return queryRec(T, 1, 0, n-1, l, r);
}

void updateRec(pair<int, int>* T, int* A, int node, int start, int end, int idx, int val) {
    if(start == end) {
        // A[idx] += val;
        // T[node].first += val;
        T[node].first = val;
    } else {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid) {
            updateRec(T, A, 2 * node, start, mid, idx, val);
        } else {
            updateRec(T, A, 2 * node + 1, mid + 1, end, idx, val);
        }
        T[node] = maxPair(T[2 * node], T[2 * node + 1]);    //# <======= IMPORTANTE
    }
}

void update(pair<int, int>* T, int *A, int n, int idx, int val) {
    updateRec(T, A, 1, 0, n - 1, idx, val);
}

int main() {
  string aStr, sStr;
  int swaps;
  pair<int, int> maxx;

  cin >> aStr >> sStr;
  int sizeA = aStr.size();
  int sizeS = sStr.size();

  int a[sizeA];
  int s[sizeS];
  pair<int, int> T[4 * sizeS];

  for(int i = 0; i < sizeA; i++) {
    a[i] = aStr[i] - '0';
  }

  for(int i = 0; i < sizeS; i++) {
    s[i] = sStr[i] - '0';
  }

  build(T, s, sizeS);
  int qtdReplaces = 0;
  for(int i = 0; i < sizeA && qtdReplaces < sizeS; i++) {
    maxx = query(T, sizeS, 0, sizeS - 1);

    if(maxx.first > a[i]) {
      a[i] = maxx.first;
      s[maxx.second] = -1;
      update(T, s, sizeS, maxx.second, -1);
      qtdReplaces++;
    }
  }

  for(int i = 0; i < sizeA; i++) {
    cout << a[i];
  }

  cout << endl;
  return 0;
}
