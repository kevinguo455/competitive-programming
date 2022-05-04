/*
Mock CCC '22 S2/J5 - Turnstables
Key Concepts: Implementation, Ad Hoc
https://www.hackerrank.com/contests/csec-mock-ccc-2022-senior/challenges/swappables
*/

#include <bits/stdc++.h>
using namespace std;

struct H{int ls, rs;};
map<int, H> m;  // (height, (left seen, right seen))
int c[32];      // total seen

int lg2(int n) {
    int l = 0;
    while (n >>= 1) l++;
    return l;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q; cin >> N >> Q;
    for (int i = 1, x; i <= N; i++) {
        cin >> x;
        int s = c[lg2(x)]++;
        auto it = m.find(x);
        if (it == m.end()) m[x] = {s, s};
        else it->second.rs = max(it->second.rs, s);
    }
    while (Q--) {
        int x, y; cin >> x >> y;
        auto it = m.find(y);
        if (it == m.end()) {
            cout << "NO\n";
            continue;
        }
        cout << ((it->second.ls < x && x <= N - c[lg2(y)] + it->second.rs) ? "YES" : "NO") << '\n';
    }

    return 0;
}