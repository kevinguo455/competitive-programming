/*
ECOO '21 P4 - Chris' Candy
Key Concepts: Greedy Algorithms, Intermediate Math (subset counting, prime factorization)
https://dmoj.ca/problem/ecoo21p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 1e6+5, LIM = 1e5; 

bitset<MAXN> b;
vector<ll> primes, fac;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (ll i = 2; i < MAXN; i++) {
        if (!b[i]) {
            primes.push_back(i);
            for (ll j = i; j < MAXN; j += i) {
                b[j] = 1;
            }
        }
    }

    ll K; cin >> K; K++;
    ll D = K, S = 0;
    for (ll p : primes) {
        while (D % p == 0) {
            D /= p;
            fac.push_back(p);
            S += p-1;
            if (S > LIM) {
                cout << "Sad Chris\n";
                return 0;
            }
        }
    }
    if (D > 1) {
        fac.push_back(D);
        S += D-1;
    }

    if (S > LIM || S == 0) {
        cout << "Sad Chris\n";
        return 0;
    }

    ll t = 1;
    cout << S << '\n';
    for (ll p : fac) {
        for (ll j = 1; j < p; j++) cout << t << ' ';
        t++;
    }
    cout << '\n';

    return 0;
}
