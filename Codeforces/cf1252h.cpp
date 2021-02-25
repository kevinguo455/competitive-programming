/*
Codeforces - 2019-2020 ICPC, Asia Jakarta Regional Contest (Online Mirror) - Problem H. Twin Buildings
Key Concepts: Implementation (Line Sweep)
https://codeforces.com/contest/1252/problem/H
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Land {
    int x, y;
    ll a;
};

vector<Land> v;

bool cmpY(Land a, Land b) {
    if (a.y == b.y) return a.x > b.x;
    return a.y > b.y;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        a *= 2;
        b *= 2;
        v.push_back({a, b, (ll)a*b});
    }

    ll ans = 0;
    for (Land l : v) {
        ans = max(ans, l.a/2);
    }

    sort(v.begin(), v.end(), cmpY);
    int r = v[0].x;
    for (int i = 1; i < v.size(); i++) {
        ans = max(ans, (ll)min(r, v[i].x) * v[i].y);
        r = max(r, v[i].x);
    }

    if (ans % 4 == 0) cout << ans/4 << ".0\n";
    else cout << ans/4 << ".5\n";

    return 0;
}