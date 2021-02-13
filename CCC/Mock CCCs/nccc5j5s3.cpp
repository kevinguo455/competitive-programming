/*
Mock CCC '18 Contest 5 J5/S3 - Directed Graph Connectivity
Key Concepts: Graph Theory (DFS/BFS), Brute Force
https://dmoj.ca/problem/nccc5j5s3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x, a) memset(x, a, sizeof(x))
#define pb(x) push_back(x)
#define f(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 52;

vector<int> adj[MAXN];
vector<int> ex, ey;
int rx, ry;
bool vis[MAXN];

void dfs(int n){
    if (vis[n]) return;
    vis[n] = 1;
    for(int t:adj[n]){
        if (n == rx && t == ry) continue;
        dfs(t);
    }
}

int main() {
    int nodes, edges, x, y; cin >> nodes >> edges;
    f(i,0,edges) {
        cin >> x >> y;
        adj[x].pb(y);
        ex.pb(x);
        ey.pb(y);
    }
    f(i,0,edges) {
        rx = ex[i];
        ry = ey[i];
        ms(vis,0);
        dfs(1);
        cout << (vis[nodes] ? "YES" : "NO") << endl;
    }
    return 0;
}