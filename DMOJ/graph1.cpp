/*
Breaking the Friend Chain
Key Concepts: Graph Theory
https://dmoj.ca/problem/graph1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+5;

vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int c) {
    vis[c] = 1;
    for (int t : adj[c]) {
        if (!vis[t]) {
            dfs(t);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;
    int a, b;
    while (M--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int S, E; cin >> S >> E;
    dfs(S);
    cout << (vis[E] ? "1\n" : "0\n");

    return 0;
}