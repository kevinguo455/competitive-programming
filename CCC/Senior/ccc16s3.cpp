/*
CCC '16 S3 - Phonomenal Reviews
Key Concepts: Graph Theory (trees, diameter, DFS/BFS)
https://dmoj.ca/problem/ccc16s3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
#define fi first
#define se second
#define fio cin.tie(0)->sync_with_stdio(0)
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5;

vector<int> adj[MAXN];
bool pho[MAXN];     // pho restaurants
bool valid[MAXN];   // valid nodes after tree is pruned 
bool vis[MAXN];
int dist[MAXN];
int validAmount, diameter;

// prune tree recursively
void prune(int c) {
    vis[c] = 1;
    if (pho[c]) valid[c] = 1;
    for (int t:adj[c]) {
        if (!vis[t]) {
            prune(t);
            valid[c] = valid[c] | valid[t];
        }
    }
    if (valid[c]) validAmount++;
}

void dfs(int c) {
    diameter = max(diameter, dist[c]);
    vis[c] = 1;
    for (int t:adj[c]) {
        if (valid[t] && !vis[t]) {
            dist[t] = dist[c] + 1;
            dfs(t);
        }
    }
}

int main() {
    fio;

    // init
    int n, m; cin >> n >> m;
    int r, a, b; 
    for (int i = 0; i < m; i++) {
        cin >> r;
        pho[r] = 1;
    }
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    // prune tree
    prune(r);

    // find diameter: bfs
    ms(vis, 0);
    queue<int> q;
    q.push(r);
    while (!q.empty()) {
        r = q.front();
        q.pop();
        vis[r] = 1;
        for (int t:adj[r]) {
            if (valid[t] && !vis[t]) {
                q.push(t);
            }
        }
    }

    // find diameter: dfs
    ms(vis, 0);
    dfs(r);

    cout << (validAmount-1)*2 - diameter << "\n";

    return 0;
}