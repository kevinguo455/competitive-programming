/*
Glenforest Spring Open 2015 Senior 4 - Mostly Talking
Key Concepts: Graph Theory (Dijkstra's)
https://dmoj.ca/problem/gfssoc2s4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9, MAXN = 5e5+5;

struct Edge{int n, w;};

vector<Edge> adjf[MAXN];
vector<Edge> adjb[MAXN];

int distf[MAXN];
int distb[MAXN];

bool cmpf(int a, int b) {
    return distf[a] > distf[b];
}

bool cmpb(int a, int b) {
    return distb[a] > distb[b];
}

void dijkstra(int n, vector<Edge>* adj, int* dist, function<bool(int, int)> cmp) {
    
    priority_queue<int, vector<int>, function<bool(int, int)>> pq(cmp);
    fill(dist, dist + MAXN, INF);
    pq.push(n);
    dist[n] = 0;
    
    while (!pq.empty()) {
        int c = pq.top(); pq.pop();
        for (Edge t : adj[c]) {
            if (dist[c] + t.w < dist[t.n]) {
                dist[t.n] = dist[c] + t.w;
                pq.push(t.n);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init graphs
    int N, M; cin >> N >> M;
    int a, b, w;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> w;
        adjf[a].push_back({b, w});
        adjb[b].push_back({a, w});
    }

    // forward dijkstra
    dijkstra(1, adjf, distf, cmpf);

    // backward dijkstra
    dijkstra(N, adjb, distb, cmpb);

    // check cindy's paths
    int ans = distf[N];
    int C; cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> a >> b >> w;
        ans = min(ans, distf[a] + w + distb[b]);
    }
    if (ans == INF) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}