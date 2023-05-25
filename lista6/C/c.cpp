#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n, k, result;
	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n >> k;
		result = n * (k / (n - 1)) + (k % (n - 1));
		if(k % (n - 1) == 0) {
			result--;
		} 
		cout << result << endl;
	}

	return 0;
}
