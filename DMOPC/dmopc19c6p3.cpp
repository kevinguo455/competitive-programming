/*
DMOPC '19 Contest 6 P3 - Grade 11 Math
Key Concepts: Intermediate Math (binary representation)
https://dmoj.ca/problem/dmopc19c6p3
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5+5, MOD = 1e9+7; 

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
        p /= 2;
        n = mul(n, n);
    }
    return a;
}

set<int, greater<int>> s;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q; cin >> N >> Q;
    ll ans = 0;
    
    char d;
    ll p = binexp(2, N-1);
    ll MODINV2 = binexp(2, MOD-2);
    for (int i = 0; i < N; i++) {
        cin >> d;
        if (d == '1') ans = add(ans, p);
        else s.insert(N-i-1);
        p = mul(p, MODINV2);
    }

    int a, b;
    while (Q--) {
        cin >> a >> b;
        auto it = s.lower_bound(N-a);
        while (it != s.end() && *it >= N-b) {
            ans = add(ans, binexp(2, *it));
            it = s.erase(it);
        }
        cout << ans << '\n';
    }

    return 0;
}