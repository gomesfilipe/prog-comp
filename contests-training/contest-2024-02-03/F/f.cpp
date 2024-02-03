#include <bits/stdc++.h>

#define endl '\n'
#define mp make_pair
#define pii pair<int, int>

using namespace std;

typedef long long ll;
ll _sieve_size;
bitset<10000010> bs; // 10^7 is the rough limit
vector<ll> p;               // compact list of primes
void sieve(ll upperbound)
{                                 // range = [0..upperbound]
    _sieve_size = upperbound + 1; // to include upperbound
    bs.set();                     // all 1s
    bs[0] = bs[1] = 0;            // except index 0+1
    for (ll i = 2; i < _sieve_size; ++i)
        if (bs[i])
        {
            // cross out multiples of i starting from i*i
            for (ll j = i * i; j < _sieve_size; j += i)
                bs[j] = 0;
            p.push_back(i); // add prime i to the list
        }
}
bool isPrime(ll N)
{ // good enough prime test
    if (N < _sieve_size)
        return bs[N]; // O(1) for small primes
    for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i)
        if (N % p[i] == 0)
            return false;
    return true; // slow if N = large prime
} // note: only guaranteed to work for N <= (last prime in vll p)^2

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int a, b;
    cin >> a >> b;
    
    sieve(b);
    for(int i = a; i <= b; i++){
        if(isPrime(i)) cout << i << " ";
    }

return 0;
}