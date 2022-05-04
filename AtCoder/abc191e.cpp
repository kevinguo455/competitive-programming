/*
E - Come Back Quickly 
Key Concepts: Graph Theory (Dijkstra's)
https://atcoder.jp/contests/abc191/tasks/abc191_e
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3+1; 

struct Edge{int n, w;};
vector<Edge> adj[MAXN];
int dist[MAXN];

bool cmp(Edge a, Edge b) {
    return a.w > b.w;
}

int dijkstra(int n) {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> pq(cmp);
    pq.push({n, 0});
    while (!pq.empty()) {
        Edge c = pq.top(); pq.pop();
        if (c.n == n && c.w > 0) return c.w;
        for (Edge t : adj[c.n]) {
            if (c.w + t.w < dist[t.n]) {
                dist[t.n] = c.w + t.w;
                pq.push({t.n, dist[t.n]});
            }
        }
    }
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, E; cin >> N >> E;

    int a, b, w;
    while (E--) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    
    for (int i = 1; i <= N; i++) {
        cout << dijkstra(i) << '\n';
    }

    return 0;
}