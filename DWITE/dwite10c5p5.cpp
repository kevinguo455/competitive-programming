/*
DWITE '10 R5 #5 - Cube World
Key Concepts: Brute Force, DFS/BFS
https://dmoj.ca/problem/dwite10c5p5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define fi first
#define se second
typedef pair<int, int> pii;
const int MAXN = 21; 

int arr[MAXN][MAXN];
int rows, cols;
vector<pii> v;

// sort coordinates in increasing order of height
bool cmp(pii a, pii b) {
    return arr[a.fi][a.se] < arr[b.fi][b.se];
}

bool vis[MAXN][MAXN];

// does water added at this point spill?
bool dfs(pii c) {
    if (c.fi == 0 || c.se == 0 || c.fi == rows-1 || c.se == cols-1) return 1;
    if (vis[c.fi][c.se]) return 0;

    vis[c.fi][c.se] = 1;
    bool ans = 0;
    if (!ans && arr[c.fi-1][c.se] <= arr[c.fi][c.se]) ans |= dfs({c.fi-1, c.se});
    if (!ans && arr[c.fi+1][c.se] <= arr[c.fi][c.se]) ans |= dfs({c.fi+1, c.se});
    if (!ans && arr[c.fi][c.se-1] <= arr[c.fi][c.se]) ans |= dfs({c.fi, c.se-1});
    if (!ans && arr[c.fi][c.se+1] <= arr[c.fi][c.se]) ans |= dfs({c.fi, c.se+1});

    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int cases = 0; cases < 5; cases++) {
        cin >> rows >> cols;

        // init
        v.clear();
        ms(arr, 0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> arr[i][j];
                v.emplace_back(i, j);
            }
        }
        sort(v.begin(), v.end(), cmp);

        // naive brute force: keep adding one drop of water to each point as long as it doesn't spill
        int ans = 0;
        bool quit = 0;
        while (!quit) {
            quit = 1;
            for (int i = 0; i < (int) v.size(); i++) {
                ms(vis, 0);
                if (!dfs(v[i])) {
                    quit = 0;
                    arr[v[i].fi][v[i].se]++;
                    ans++;
                    sort(v.begin(), v.end(), cmp);
                    break;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}