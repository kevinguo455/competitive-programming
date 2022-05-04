/*
Back to School '16: Times Table
Key Concepts: 2D Difference Array, First Differences, Graph Theory (BFS)
https://dmoj.ca/problem/bts16p6
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 505, MOD = 1e9+7, dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int C, R, M, sc, sr;
ll arr[MAXN][MAXN][2];     // [1] = First difference, [0] = Actual values
ll path[MAXN][MAXN][2];    // [1] = Sum, [0] = Length

void dfs(int r, int c) {
    if (path[r][c][0]) return;

    path[r][c][0] = 1;
    path[r][c][1] = arr[r][c][0];

    for (auto dir : dirs) {
        int tr = r+dir[0];
        int tc = c+dir[1];
        if (tr > 0 && tr <= R && tc > 0 && tc <= C && arr[tr][tc][0] > arr[r][c][0]) {
            dfs(tr, tc);
            if (path[tr][tc][0] + 1 > path[r][c][0]) {
                path[r][c][0] = path[tr][tc][0] + 1;
                path[r][c][1] = path[tr][tc][1] + arr[r][c][0];
            }
            else if (path[tr][tc][0] + 1 == path[r][c][0]) {
                path[r][c][1] = max(path[r][c][1], path[tr][tc][1] + arr[r][c][0]);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> C >> R >> M;

    // Construct difference array
    for (int i = 1, c1, r1, w, h, n; i <= M; i++) {
        cin >> c1 >> r1 >> w >> h >> n;
        int r2 = r1+h, c2 = c1+w;
        int xd = -n*h, yd = -n*w;
        
        // Add first differences
        arr[r1][c1][1] += n;
        arr[r1][c2][1] -= n;
        arr[r2][c1][1] -= n;
        arr[r2][c2][1] += n;
 
        // Reset first differences
        arr[r2][c1][1] += xd;
        arr[r2+1][c1][1] -= xd;
        arr[r2][c2][1] -= xd;
        arr[r2+1][c2][1] += xd;

        arr[r1][c2][1] += yd;
        arr[r1][c2+1][1] -= yd;
        arr[r2][c2][1] -= yd;
        arr[r2][c2+1][1] += yd;

        // Reset actual values
        arr[r2][c2][0] += n*w*h;
    }

    // Accumulate difference array
    for (int r = 1; r <= MAXN-1; r++) {
        for (int c = 1; c <= MAXN-1; c++) {
            arr[r][c][1] = arr[r][c][1] + arr[r-1][c][1] + arr[r][c-1][1] - arr[r-1][c-1][1];
            arr[r][c][0] = arr[r][c][0] + arr[r-1][c][0] + arr[r][c-1][0] - arr[r-1][c-1][0] + arr[r][c][1];
        }
    }

    cin >> sc >> sr;
    dfs(sr, sc);
    cout << path[sr][sc][1] % MOD << '\n';

    return 0;
}