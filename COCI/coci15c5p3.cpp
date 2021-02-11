/*
COCI '15 Contest 5 #3 Perica
Key Concepts: Intermediate Math (binomial coefficients)
https://dmoj.ca/problem/coci15c5p3
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+5, MOD = 1e9+7; 

ll fac[MAXN];
ll inv[MAXN];
ll invfac[MAXN];

inline ll sum(ll a, ll b) {
    return (a+b) % MOD;
}

inline ll mul(ll a, ll b) {
    return (a*b) % MOD;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fac[i] = mul(fac[i-1], i);

    inv[1] = 1;
    for (int i = 2; i < MAXN; i++)
        inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;
    
    invfac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        invfac[i] = mul(invfac[i-1], inv[i]);
    }
}

inline ll c(int n, int k) {
    return mul(fac[n], mul(invfac[k], invfac[n-k]));
}

int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    init();

    int N, K; cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    ll ans = 0;

    for (int i = K-1; i < N; i++) {
        ans = sum(ans, mul(arr[i], c(i, K-1)));
    }

    cout << ans << '\n';

    return 0;
}