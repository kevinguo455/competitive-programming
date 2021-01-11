/*
VM7WC '16 #3 Gold - Hello, Officer.
Key Concepts: Graph Theory (SSSP)
https://dmoj.ca/problem/vmss7wc16c3p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
const int INF = 0x3f3f3f3f, MAXN = 2005; 

struct Edge{int n, w;};

vector<Edge> adj[MAXN];
int dist[MAXN];

bool cmp(int a, int b) {
    return dist[a] > dist[b];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    int n, m, b, q; cin >> n >> m >> b >> q;
    int x, y, z;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    // dijkstra's
    ms(dist, INF);
    dist[b] = 0;
    priority_queue<int, vector<int>, function<bool(int,int)>> pq(cmp);
    pq.push(b);
    while (!pq.empty()) {
        int c = pq.top();
        pq.pop();
        for (Edge t : adj[c]) {
            if (dist[c] + t.w < dist[t.n]) {
                dist[t.n] = dist[c] + t.w;
                pq.push(t.n);
            }
        }
    }

    // queries
    for (int i = 0; i < q; i++) {
        cin >> x;
        if (dist[x] == INF) cout << "-1\n";
        else cout << dist[x] << "\n";
    }

    return 0;
}