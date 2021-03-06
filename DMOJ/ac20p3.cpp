/*
Appleby Contest '20 P3 - Ridiculous String
Key Concepts: Implementation
https://dmoj.ca/problem/ac20p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 26; 

set<int> pos[MAXN];
bool good[MAXN];

inline int m(char c) {
    return c - 'a';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;
    char c;
    for (int i = 0; i < N; i++) {
        cin >> c;
        pos[m(c)].insert(i);
        good[m(c)] = 1;
    }

    ll ans = 0;
    int idx = -1;
    for (int i = 0; i < M; i++) {
        cin >> c;
        if (!good[m(c)]) {
            cout << "-1\n";
            return 0;
        }
        auto it = pos[m(c)].upper_bound(idx);
        if (it == pos[m(c)].end()) {
            ans += N-idx-1;
            idx = -1;
            it = pos[m(c)].upper_bound(idx);
        }
        ans += *it - idx;
        idx = *it;
    }
    cout << ans << '\n';

    return 0;
}