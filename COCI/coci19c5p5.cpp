/*
COCI '19 Contest 5 #5 Zapina
Key Concepts: Dynamic Programming, Intermediate Math (binomial coefficients, binary exponentiation)
https://dmoj.ca/problem/coci19c5p5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 351, MOD = 1e9+7;

inline ll add(ll a, ll b) {
    return (a+b)%MOD;
}

inline ll sub(ll a, ll b) {
    return (a-b+MOD)%MOD;
}

inline ll mul(ll a, ll b) {
    return (a*b)%MOD;
}

ll fac[MAXN];
ll inv[MAXN];

ll binexp(ll n, ll p) {
    ll a = 1;
    while (p) {
        if (p&1) a = mul(a, n);
        n = mul(n, n);
        p /= 2;
    }
    return a;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fac[i] = mul(fac[i-1], i);

    inv[0] = 1;
    for (int i = 1; i < MAXN; i++) 
        inv[i] = binexp(fac[i], MOD-2);
}

ll c(int n, int k) {
    return mul(fac[n], mul(inv[k], inv[n-k]));
}

ll dp[MAXN][MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    init();

    int N; cin >> N;
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == j) continue;
            for (int k = j; k <= N; k++) {
                dp[i][k] = add(dp[i][k], mul(dp[i-1][k-j], c(k, j)));
            }
        }
    }
    cout << sub(binexp(N, N), dp[N][N]) << '\n';

    return 0;
}