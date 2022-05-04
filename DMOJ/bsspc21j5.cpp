/*
BSSPC '21 J5 - James and the Euclid Test
Key Concepts: Prefix Sum Array, Prime Sieve
https://dmoj.ca/problem/bsspc21j5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXV = 1e6+5; 

bitset<MAXV> sieve;
vector<int> primes;
vector<ll> psa;

void init() {
    for (int i = 2; i < MAXV; i++) {
        if (!sieve[i]) {
            primes.push_back(i);
            psa.push_back(i);
        }
        for (int j = 2*i; j < MAXV; j += i) {
            sieve[j] = 1;
        }
    }
    for (int i = 1; i < (int)psa.size(); i++) {
        psa[i] += psa[i-1];
    }
}

inline int idx(int x) {
    return lower_bound(primes.begin(), primes.end(), x) - primes.begin();
}

inline ll sum(int idx, int k) {
    if (idx == 0) return psa[idx+k-1];
    return psa[idx+k-1] - psa[idx-1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    init();

    int Q, x, k, p; cin >> Q;
    while (Q--) {
        cin >> x >> k;
        p = idx(x);
        cout << primes[p+k-1] << ' ' << sum(p, k) << '\n';
    }

    return 0;
}