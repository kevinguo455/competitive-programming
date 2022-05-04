/*
Appleby Contest '19 P5 - Matrix Operation
Key Concepts: Dynamic Programming (sorting)
https://dmoj.ca/problem/ac19p5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1505;

int N, arr[MAXN][MAXN], dp[MAXN][MAXN];

struct Cell{int val, r, c;} cells[MAXN*MAXN];
bool cmp(Cell a, Cell b) {
    return a.val < b.val;
}

inline void check(int &ret, int val, int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return;
    if (arr[r][c] < val) ret = max(ret, dp[r][c]+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> arr[r][c];
            cells[r*N+c] = {arr[r][c], r, c};
        }
    }

    sort(cells, cells+N*N, cmp);

    int ans = 0;

    for (int i = 0; i < N*N; i++) {
        check(dp[cells[i].r][cells[i].c], cells[i].val, cells[i].r+1, cells[i].c);
        check(dp[cells[i].r][cells[i].c], cells[i].val, cells[i].r-1, cells[i].c);
        check(dp[cells[i].r][cells[i].c], cells[i].val, cells[i].r, cells[i].c+1);
        check(dp[cells[i].r][cells[i].c], cells[i].val, cells[i].r, cells[i].c-1);
        ans = max(ans, dp[cells[i].r][cells[i].c]);
    }

    cout << ans << '\n';

    return 0;
}