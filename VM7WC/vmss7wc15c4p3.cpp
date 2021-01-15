/*
VM7WC '15 #4 Gold - Chain Rule
Key Concepts: Graph Theory (Dijkstra's)
https://dmoj.ca/problem/vmss7wc15c4p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
const int INF = 0x3f3f3f3f, MAXN = 1e5+5; 

struct Edge{int n, w;};

vector<Edge> adj[MAXN];
int dist0[MAXN];
int dist1[MAXN];

bool cmp(Edge a, Edge b) {
    return a.w > b.w;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    int nodes, edges; cin >> nodes >> edges;
    int a, b, c;
    for (int i = 0; i < edges; i++) {
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    // compute distance from start
    ms(dist0, INF);
    dist0[0] = 0;
    priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> pq(cmp);
    pq.push({0, 0});
    while (!pq.empty()) {
        Edge c = pq.top();
        pq.pop();
        if (c.w > dist0[c.n]) continue;
        for (Edge t : adj[c.n]) {
            if (c.w + t.w < dist0[t.n]) {
                dist0[t.n] = c.w + t.w;
                pq.push({t.n, dist0[t.n]});
            }
        }
    }

    // compute distance from end, keep track of ans
    ms(dist1, INF);
    dist1[nodes-1] = 0;
    int ans = 0;
    pq.push({nodes-1, 0});
    while (!pq.empty()) {
        Edge c = pq.top();
        pq.pop();
        if (c.w > dist1[c.n]) continue;

        ans = max(ans, dist0[c.n] + dist1[c.n]); // ans is sum of distance from point to start and end
        
        for (Edge t : adj[c.n]) {
            if (c.w + t.w < dist1[t.n]) {
                dist1[t.n] = c.w + t.w;
                pq.push({t.n, dist1[t.n]});
            }
        }
    }

    cout << ans << "\n";

    return 0;
}