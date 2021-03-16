/*
DMOPC '20 Contest 4 P2 - Beautiful Grids
Key Concepts: Implementation
https://dmoj.ca/problem/dmopc20c4p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<ll> x, y;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, M, K; cin >> N >> M >> K;
    for (ll i = 0, a, b; i < K; i++) {
        cin >> a >> b;
        auto ita = x.find(a), itb = y.find(b);
        if (ita == x.end()) x.insert(a);
        else x.erase(ita);
        if (itb == y.end()) y.insert(b);
        else y.erase(itb);
    }

    // A value
    cout << max(x.size(), y.size()) << '\n';

    auto itx = x.begin(), ity = y.begin();

    if (x.size() <= y.size()) {
        for (; itx != x.end(); itx++, ity++) {
            cout << *itx << ' ' << *ity << '\n';
        }
        for (; ity != y.end(); ity++) {
            cout << 1 << ' ' << *ity << '\n';
        }
    }
    else {
        for (; ity != y.end(); itx++, ity++) {
            cout << *itx << ' ' << *ity << '\n';
        }
        for (; itx != x.end(); itx++) {
            cout << *itx << ' ' << 1 << '\n';
        }
    }

    return 0;
}