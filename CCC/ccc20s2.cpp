// https://dmoj.ca/problem/ccc20s2
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;
int r, c;
vector<int> path[MAXN];
bool vis[MAXN];
bool quit = 0;

void dfs(int s) {
    if (s == r*c) quit = 1;
    if (quit) return;
    vis[s] = 1;
    for (int x:path[s]) {
        if (!vis[x]) dfs(x);
        if (quit) return;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int x; cin >> x;
            path[i*j].push_back(x);
        }
    }
    dfs(1);
    cout << (quit?"yes":"no") << endl;
    return 0;
}
