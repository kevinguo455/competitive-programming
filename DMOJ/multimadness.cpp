/*
Multiplication Madness
Key Concepts: Prefix Sum Array, Modular Inverses
https://dmoj.ca/problem/multimadness
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6+5, MOD = 1e9+7; 

int fac[MAXN];
int inv[MAXN];
int facinv[MAXN];

inline int mul(int a, int b) {
    return (int) ((ll)a * (ll)b % MOD);
}

void init() {
    fac[1] = 1;
    for (int i = 2; i < MAXN; i++) 
        fac[i] = mul(fac[i-1], i);
    
    inv[1] = 1;
    for (int i = 2; i < MAXN; i++)
        inv[i] = MOD - mul(MOD/i, inv[MOD%i]) % MOD;
    
    facinv[1] = 1;
    for (int i = 2; i < MAXN; i++) 
        facinv[i] = mul(facinv[i-1], inv[i]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    init();

    int N; cin >> N;
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        if (a == 0) cout << 0 << '\n';
        else if (a == 1) cout << fac[b] << '\n';
        else cout << mul(fac[b], facinv[a-1]) << '\n';
    }

    return 0;
}