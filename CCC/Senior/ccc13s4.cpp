/*
CCC '13 S4 - Who is Taller?
Key Concepts: Graph Theory (BFS/DFS)
https://dmoj.ca/problem/ccc13s4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
const int MAXN = 1e6+5; 

vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int c) {
    vis[c] = 1;
    for (int t : adj[c]) {
        if (!vis[t]) dfs(t);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    int n, e; cin >> n >> e;
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        adj[a].pb(b);
    }

    // solve
    cin >> a >> b;
    dfs(a);
    if (vis[b]) {
        cout << "yes\n";
        return 0;
    }
    ms(vis, 0);
    dfs(b);
    
    if (vis[a]) cout << "no\n";
    else cout << "unknown\n";

    return 0;
}