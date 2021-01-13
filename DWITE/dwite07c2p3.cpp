/*
DWITE '07 R2 #3 - Floor Plan
Key Concepts: Graph Theory (Grid, Components)
https://dmoj.ca/problem/dwite07c2p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
const int MAXN = 41;

int ans = 0;
int rows, cols;
bool vis[MAXN][MAXN];

int dfs(int r, int c) {
    if (r < 0 || c < 0 || r >= rows || c >= cols) return 0;
    if (vis[r][c]) return 0;
    vis[r][c] = 1;
    return 1 + dfs(r, c+1) + dfs(r, c-1) + dfs(r+1, c) + dfs(r-1, c);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int roomCount = 0;
    pii rooms[5];

    // init
    cin >> rows >> cols;
    for (int i = 0; i < rows; i++) {
        string s; cin >> s;
        for (int j = 0; j < cols; j++) {
            if (s[j] == '#') {
                vis[i][j] = 1;
            }
            else if (s[j] >= '1' && s[j] <= '5') {
                rooms[s[j]-'1'] = {i, j};
                roomCount++;
            }
        }
    }

    // search rooms
    for (int i = 0; i < roomCount; i++) {
        cout << dfs(rooms[i].fi, rooms[i].se) << "\n";
    }

    return 0;
}