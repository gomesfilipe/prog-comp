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
  string numStr;
  int swaps;
  pair<int, int> maxx;

  cin >> numStr >> swaps;
  int n = numStr.size();

  int num[n];
  pair<int, int> T[4 * n];

  for(int i = 0; i < n; i++) {
    num[i] = numStr[i] - '0';
  }

  build(T, num, n);

  for(int i = 0; i < n; i++) {
    maxx = query(T, n, i + 1, i + swaps);

    if(maxx.first <= num[i]) {
      continue;
    }

    for(int j = maxx.second; j > i; j--) {
      int tmp = num[j];
      num[j] = num[j - 1];
      num[j - 1] = tmp;
      swaps--;

      update(T, num, n, j, num[j]);
      update(T, num, n, j - 1, num[j - 1]);
    }

    if(swaps == 0) break;
  }

  for(int i = 0; i < n; i++) {
    cout << num[i];
  }

  cout << endl;
  return 0;
}
