/*
Glenforest Spring Open '14 Junior 1 - Flying Plushies
Key Concepts: Implementation
https://dmoj.ca/problem/gfssoc1j1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, x, ans = 0; cin >> N >> M;
    while (M--) {
        cin >> x;
        ans += (x >= N);
    }
    cout << ans << '\n';

    return 0;
}