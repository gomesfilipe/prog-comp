#include <iostream>
#include <algorithm>

using namespace std;

long long int values[100];
long long int weights[100];

long long int F[101][100001];

void printInput(long long int n);
void initF(long long int n, long long int w);
long long int knapsack(long long i, long long j);
void printF(long long int n, long long int w);


int main() {
    long long int n, w;
    cin >> n >> w;

    initF(n + 1, w + 1);

    for(long long int i = 1; i <= n; i++) {
        cin >> weights[i] >> values[i];
    }

    cout << knapsack(n, w) << endl;

    // printF(n + 1, w + 1);
    // printInput(n);
    return 0;
}

void printInput(long long int n) {
    for(int i = 0; i < n; i++) {
        cout << weights[i] << " " << values[i] << endl;
    }
    return;
}

long long int knapsack(long long int i, long long int j) {
    long long  value;

    if(F[i][j] < 0) {
        if(j < weights[i]) { // item nao cabe na mochila
            value = knapsack(i - 1, j); // nao pega o i-esimo e continua do i - 1
        } else {
            value = max( // pega o maior entre nao pegar o item ou pegar o item
                knapsack(i - 1, j), 
                values[i] + knapsack(i - 1, j - weights[i])
            );
        }
        F[i][j] = value;
    }

    return F[i][j];
}

void initF(long long int n, long long int w) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < w; j++) {
            if(i == 0 || j == 0) {
                F[i][j] = 0;
            } else {
                F[i][j] = -1;
            }
        }
    }
    return;
}

void printF(long long int n, long long int w) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < w; j++) {
            cout << F[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
