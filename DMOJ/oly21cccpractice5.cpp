#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = (1<<4), MAXM = 4, MOD = 998244353; 


int N, M; 
int arr[MAXM];

bool is_set(int n, int d) {
    return (n >> d) & 1;
}

int occ(int r) {
    return N/r;
}

inline ll add(ll a, ll b) {
    return (a+b)%MOD;
}

inline ll mul(ll a, ll b) {
    return (a*b)%MOD;
}

ll binexp(ll n, int p) {
    ll a = 1;
    while (p) {
        if (p&1) a = mul(a, n);
        n = mul(n, n);
        p /= 2;
    }
    return a;
}

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll lcm(ll a, ll b) {
    return mul(mul(a, b), binexp(gcd(a, b), MOD-2));
}

ll dp[MAXN];
ll res[MAXM+1];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> arr[i];

    for (int state = (1<<M)-1; state >= 0; state--) {
        ll l = 1;
        int d = state;
        int c = 0;
        for (int i = 0; i < M; i++) {
            if (d & 1) {
                l = lcm(l, arr[i]);
                c++;
            }
            d = d >> 1;
        }
        dp[state] = occ(l);
        res[c] += dp[state];
    }

    res[0] = N;
    for (int c = M-1; c >= 0; c--) {
        res[c] -= res[c+1];
    }

    ll ans = 0;
    for (int c = M; c >= 0; c--) {
        ll t = 0;
    }

    cout << mul(ans, binexp(binexp(2, M), MOD-2)) << '\n';

    return 0;
}