#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> pll;
const int MOD = 1e9+7, INV2 = 5e8+4; 

vector<pll> v;

inline ll add(ll a, ll b) {
    return (a + b) % MOD;
}

inline ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    ll a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    ll ans = 0, t = 0;
    for (int i = 0; i < n; i++) {
        ll p = mul(v[i].fi, v[i].se);
        ans = add(ans, add(mul(v[i].se, t), mul(v[i].se+1, mul(p, INV2))));
        t = add(t, p);
    }

    cout << ans << "\n";

    return 0;
}