/*
Shortest Path
Key Concepts: Graph Theory (Bellman-Ford)
https://dmoj.ca/problem/graph3p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+5;

struct Edge{int a, b, w;};

vector<Edge> v;
int dist[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, E; cin >> N >> E;
    int a, b, w;
    while (E--) {
        cin >> a >> b >> w;
        v.push_back({a, b, w});
    }

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 1; i < N; i++) {
        for (Edge e : v) {
            dist[e.b] = min(dist[e.b], dist[e.a] + e.w);
        }
    }

    cout << dist[N] << "\n";

    return 0;
}