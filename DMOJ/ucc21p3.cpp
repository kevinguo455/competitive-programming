/*
UCC Coding Competition '21 P3 - Long Pizza
Key Concepts: Data Structures (Prefix Sum Array)
https://dmoj.ca/problem/ucc21p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e7+5; 

int diff[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    int x, y; cin >> x >> y;
    int R; cin >> R;

    // Update ranges
    for (int i = 0, l, r; i < R; i++) {
        cin >> l >> r;
        diff[l]++;
        diff[r+1]--;
    }

    // Accumulate difference array
    for (int i = 0; i < N; i++) {
        diff[i+1] += diff[i];
    }

    // Calculate range sum
    ll ans = 0;
    for (int i = x; i <= y; i++) {
        ans += diff[i];
    }

    cout << ans << '\n';

    return 0;
}