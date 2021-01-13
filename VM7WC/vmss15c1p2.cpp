/*
VMSS '15 #2 - Tomb Robbing
Key Concepts: Graph Theory (Grid, Components)
https://dmoj.ca/problem/vmss15c1p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 101;

int ans = 0;
int rows, cols;
bool vis[MAXN][MAXN];

void dfs(int r, int c) {
    if (r < 0 || c < 0 || r >= rows || c >= cols) return;
    if (vis[r][c]) return;
    vis[r][c] = 1;
    dfs(r, c+1);
    dfs(r, c-1);
    dfs(r+1, c);
    dfs(r-1, c);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    cin >> rows >> cols;
    for (int i = 0; i < rows; i++) {
        string s; cin >> s;
        for (int j = 0; j < cols; j++) {
            if (s[j] == 'X') vis[i][j] = 1;
        }
    }

    // find components
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!vis[i][j]) {
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}