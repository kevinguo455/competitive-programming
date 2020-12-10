/*
VM7WC '16 #5 Gold - Jayden Studies Trees
Key Concepts: Graph theory (radius of a tree)
https://dmoj.ca/problem/vmss7wc16c5p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 500005;

struct Edge{int w, n;};

vector<Edge> adj[MAXN];
Edge parent[MAXN];
bool vis[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int nodes; cin>>nodes;  // init
    f(i,0,nodes-1) {
        int u,v;cin>>u>>v;
        adj[u].push_back({1,v});
        adj[v].push_back({1,u});
    }

    // bfs1
    queue<Edge> q;
    q.push({0,1});
    Edge l = {0,0};
    while (!q.empty()) {
        Edge c = q.front();
        q.pop();
        vis[c.n] = 1;
        if (c.w > l.w) {
            l.w = c.w;
            l.n = c.n;
        }
        for (Edge t:adj[c.n]) {
            if (!vis[t.n])
                q.push({t.w+c.w,t.n});
        }
    }
    ms(vis,0);
    // bfs2
    q.push({0,l.n});
    parent[l.n] = {0,-1};
    Edge d = {0,0};
    while (!q.empty()) {
        Edge c = q.front();
        q.pop();
        vis[c.n] = 1;
        if (c.w > d.w) {
            d.w = c.w; 
            d.n = c.n;
        }
        for (Edge t:adj[c.n]) {
            if (vis[t.n]) continue;
            parent[t.n] = {t.w,c.n};
            q.push({t.w+c.w,t.n});
        }
    }

    cout << d.w << endl;
    return 0;
}