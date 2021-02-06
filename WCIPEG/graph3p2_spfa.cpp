/*
Shortest Path
Key Concepts: Graph Theory (SPFA)
https://dmoj.ca/problem/graph3p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+5;

struct Edge{int n, w;};

vector<Edge> adj[MAXN];
int dist[MAXN];
bool inq[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, E; cin >> N >> E;
    int a, b, w;
    while (E--) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int c = q.front(); q.pop();
        inq[c] = 0;
        for (Edge t : adj[c]) {
            if (dist[c] + t.w < dist[t.n]) {
                dist[t.n] = dist[c] + t.w;
                if (!inq[t.n]) q.push(t.n);
                inq[t.n] = 1;
            }
        }
    }

    cout << dist[N] << "\n";

    return 0;
}