/*
CCC '09 S4 - Shop and Ship
Key Concepts: Graph Theory (O(N^2) Dijkstra's)
https://dmoj.ca/problem/ccc09s4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005, INF = 0x3f3f3f3f;

int N, E;
int adj[MAXN][MAXN];
int dist[MAXN];
bool vis[MAXN];

int min_dist_vertex() {
    int min_dist = INF, min_idx = -1;
    for (int i = 1; i <= N; i++) {
        if (!vis[i] && dist[i] < min_dist) {
            min_dist = dist[i];
            min_idx = i;
        }
    }
    return min_idx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
     
    cin >> N >> E;
    
    memset(adj, 0x3f, sizeof adj);
    memset(dist, 0x3f, sizeof dist);

    int x, y, c; 
    while (E--) {
        cin >> x >> y >> c;
        adj[x][y] = min(adj[x][y], c);
        adj[y][x] = min(adj[y][x], c);
    }
    
    int S; cin >> S;
    while (S--) {
        cin >> x >> c;
        dist[x] = c;
    }

    for (int mst = 1; mst < N; mst++) {
        int c = min_dist_vertex();
        vis[c] = 1;
        for (int t = 0; t < N; t++) {
            if (!vis[t]) {
                dist[t] = min(dist[t], dist[c] + adj[c][t]);
            }
        }
    }

    int D; cin >> D;
    cout << dist[D] << '\n';

    return 0;
}