/*
DMOPC '15 Contest 1 P4 - Itami and Candy
Key Concepts: Simple Math (Prime Sieve), Implementation
https://dmoj.ca/problem/dmopc15c1p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 150000; 

bitset<MAXN> sieve;
vector<int> primes;

int main() {

    // Sieve of Eratosthenes 
    for (int i = 2; i < MAXN; i++) {
        if (sieve[i]) continue;
        primes.push_back(i);
        for (int j = 2*i; j < MAXN; j += i) sieve[j] = 1;
    }

    cin.tie(0)->sync_with_stdio(0);

    int N, X; cin >> N >> X;
    int ans = 0; 

    for (int P : primes) {
        if (P > N) break;
        ans += (N - P) / X + 1;
        if (N != P) ans += (N - P - 1) / X + 1;
    }

    cout << ans << '\n';

    return 0;
}