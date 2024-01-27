#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char linha[1000];


int countComparisons = 0;

void insertionSort(char arr[], int n)
{
    countComparisons = 0;
    int i, key, j;
    for (i = 1; i < n; i++) {
        countComparisons++;
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            countComparisons++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n;
    cin >> n;
    fgets(linha, 1000, stdin);

    for (int i = 0; i < n; i++)
    {
        fgets(linha, 1000, stdin);
        insertionSort(linha, strlen(linha) - 1);

        printf("%d\n", countComparisons);
    }

    return 0;
}