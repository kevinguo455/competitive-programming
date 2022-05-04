/*
MWC '15 #7 P2: Thief in the Night
Key Concepts: Implementation, Simple Math
https://dmoj.ca/problem/mwc15c7p2
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+5;

int arr[MAXN][6];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int F, R; cin >> F >> R;
    for (int f = 1; f <= F; f++) {
        for (int r = 1; r <= R; r++) {
            cin >> arr[r][f];
            arr[r][f] += arr[r-1][f];
        }
    }
    int Q; cin >> Q;
    for (int q = 1, l, r, f; q <= Q; q++) {
        cin >> l >> r >> f;
        cout << arr[r][f] - arr[l-1][f] << '\n';
    }

    return 0;
}