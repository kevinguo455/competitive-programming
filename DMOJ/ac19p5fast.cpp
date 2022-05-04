/*
Appleby Contest '19 P5 - Matrix Operation
Key Concepts: Dynamic Programming (memoization?)
https://dmoj.ca/problem/ac19p5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1505;

int N, arr[MAXN][MAXN], dp[MAXN][MAXN], dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solve(int r, int c) {
    if (dp[r][c]) return dp[r][c];

    for (auto d : dir) {
        #define tr r+d[0]
        #define tc c+d[1]
        if (tr >= 0 && tr < N && tc >= 0 && tc < N && arr[tr][tc] > arr[r][c]) 
            dp[r][c] = max(dp[r][c], solve(tr, tc) + 1);
    }

    return dp[r][c];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> arr[r][c];
        }
    }

    int ans = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            ans = max(ans, solve(r, c));
        }
    }
    cout << ans << '\n';

    return 0;
}