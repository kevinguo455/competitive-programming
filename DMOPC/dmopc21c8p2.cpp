/*
DMOPC '21 Contest 8 P2 - Kanna Market
Key Concepts: Ad Hoc, Binary Exponentiation
https://dmoj.ca/problem/dmopc21c8p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5, MOD = 1e9+7, INF = 0x3f3f3f3f;

ll N, M;

inline ll add(ll a, ll b) {
    return (a+b) % MOD;
}

inline ll mul(ll a, ll b) {
    return (a*b) % MOD;
}

ll qpow(ll n, ll p) {
    ll res = 1;
    while (p > 0) {
        if (p & 1) res = mul(res, n);
        n = mul(n, n);
        p /= 2;
    }
    return res;
}

ll ways(ll SUM) {
    if (SUM < 2 || SUM > 2*M) return 0;
    if (SUM <= M+1) return SUM-1;
    return 2*M+1-SUM;
}

ll solve(vector<pii> v) {
    ll SUM = 0, dbls = 0;
    for (pii p : v) {
        if (p.fi != 0 && p.se != 0) {
            if (SUM == 0) SUM = p.fi + p.se;
            else if (p.fi + p.se != SUM) return 0;
        } else if (p.fi == 0 && p.se == 0) {
            ++dbls;
        }
    }
    if (SUM != 0) {
        if (dbls != 0 && 2*M < SUM) return 0;
        for (pii p : v) {
            if (p.fi == 0 && p.se != 0) {
                if (1 + p.se > SUM || M + p.se < SUM) {
                    return 0;
                }
            }
        }
        // system is consistent
        return qpow(ways(SUM), dbls);
    } else {
        ll lo = 2, hi = 2*M;
        for (pii p : v) {
            if (p.se != 0) {
                lo = max(lo, p.se+(ll)1);
                hi = min(hi, p.se+M);
            }
        }
        ll ans = 0;
        for (int i = lo; i <= hi; ++i) {
            ans = add(ans, qpow(ways(i), dbls));
        }
        return ans % MOD;
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    vector<pii> va, vb;
    for (int i = 1, x; i <= N; ++i) {
        cin >> x;
        if (i & 1) va.push_back({x, -1});
        else vb.push_back({x, -1});
    }
    for (int i = 1, idx = 0, x; i <= N; ++i) {
        cin >> x;
        if (i & 1) {
            va[idx].se = x;
            if (va[idx].se < va[idx].fi) swap(va[idx].se, va[idx].fi);
        } else {
            vb[idx].se = x;
            if (vb[idx].se < vb[idx].fi) swap(vb[idx].se, vb[idx].fi);
            ++idx;
        }
    }

    cout << mul(solve(va), solve(vb)) << '\n';

    return 0;
}