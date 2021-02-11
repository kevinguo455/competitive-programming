/*
DMOPC '14 Contest 5 P6 - Save Nagato!
Key Concepts: Graph Theory
https://dmoj.ca/problem/dmopc14c4p6
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+5; 

int N;
vector<int> adj[MAXN];
bool vis[MAXN];
int dist1[MAXN];
int dist2[MAXN];

void dfs(int c, bool vis[], int dist[], int &maxDist, int& furthest) {
    vis[c] = 1;
    for (int t : adj[c]) {
        if (vis[t]) continue;
        dist[t] = dist[c] + 1;
        if (dist[t] > maxDist) {
            maxDist = dist[t];
            furthest = t;
        }
        dfs(t, vis, dist, maxDist, furthest);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 1, a, b; i < N; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int e1, e2, d = 0;
    dfs(1, vis, dist1, d, e1);

    d = 0;
    memset(vis, 0, sizeof vis);
    memset(dist1, 0, sizeof dist1);
    dist1[e1] = 1;
    dfs(e1, vis, dist1, d, e2);
    
    d = 0;
    memset(vis, 0, sizeof vis);
    dist2[e2] = 1;
    dfs(e2, vis, dist2, d, e1);
    
    for (int i = 1; i <= N; i++) {
        cout << max(dist1[i], dist2[i]) << '\n';
    }

    return 0;
}