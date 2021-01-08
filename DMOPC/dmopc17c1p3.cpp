/*
DMOPC '17 Contest 1 P3 - Hitchhiking Fun
Key Concepts: Graph Theory (Dijkstra's)
https://dmoj.ca/problem/dmopc17c1p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
#define fi first
#define se second
#define fio cin.tie(0)->sync_with_stdio(0)
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5; 

struct Edge{int n; bool d;};
vector<Edge> adj[MAXN];
pii dist[MAXN];     // {dangerous roads, total roads}

bool cmp(pii a, pii b) {
    if (a.fi == b.fi) return a.se < b.se;
    return a.fi < b.fi;
}

bool pqcmp(int a, int b) {
    return !cmp(dist[a], dist[b]);
}

int main() {
    fio;

    // init
    int nodes, edges; cin >> nodes >> edges;
    int a, b;
    bool c;
    f(i,0,edges) {
        cin >> a >> b >> c;
        adj[a].pb({b,c});
        adj[b].pb({a,c});
    }

    // dijkstra's
    priority_queue<int, vector<int>, function<bool(int, int)>> pq(pqcmp);
    pq.push(1);
    f(i,2,nodes+1) dist[i] = {INF, INF};

    while (!pq.empty()) {
        int c = pq.top();
        pq.pop();
        for (Edge t:adj[c]) {
            if (cmp({dist[c].fi+t.d, dist[c].se+1}, dist[t.n])) {
                dist[t.n] = {dist[c].fi+t.d, dist[c].se+1};
                pq.push(t.n);
            }
        }
    }

    if (dist[nodes].fi == INF) cout << -1 << "\n";
    else cout << dist[nodes].fi << " " << dist[nodes].se << "\n";

    return 0;
}