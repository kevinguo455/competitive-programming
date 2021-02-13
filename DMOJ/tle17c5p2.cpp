/*
TLE '17 Contest 5 P2 - Delivery Service II
Key Concepts: Greedy Algorithms
https://dmoj.ca/problem/tle17c5p2
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5, INF = 0x3f3f3f3f; 

int N, D;
int loc[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> D;
    for (int i = 1; i <= N; i++) cin >> loc[i];
    
    int left_start = INF, left_end = -INF;
    int right_start = -INF, right_end = INF;
    
    for (int i = 0, x, y; i < D; i++) {
        cin >> x >> y;
        x = loc[x];
        y = loc[y];
        if (x < y) {
            left_start = min(left_start, x);
            left_end = max(left_end, y);
        }
        else {
            right_start = max(right_start, x);
            right_end = min(right_end, y);
        }
    }

    int l = left_end - left_start;
    int r = right_start - right_end;

    if (right_start == -INF) cout << l << '\n';
    else if (left_start == INF) cout << r << '\n';
    else cout << l + r + min(abs(right_start - left_end), abs(left_start - right_end)) << '\n';

    return 0;
}