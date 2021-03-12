/*
A Noisy Class
Key Concepts: Graph Theory (cycle detection) 
https://dmoj.ca/problem/anoisyclass
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+5; 

vector<int> adj[MAXN];
short vis[MAXN];
bool cycle;

void dfs(int c) {
    vis[c] = 1;
    for (int t : adj[c]) {
        if (vis[t] == 1) {
            cycle = 1;
            return;
        }
        if (vis[t] == 0) dfs(t);
    }
    vis[c] = 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;
    for (int i = 1, a, b; i <= M; i++) { 
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        if (!vis[i]) dfs(i);
        if (cycle) break;
    }

    cout << (cycle ? "N\n" : "Y\n");

    return 0;
}