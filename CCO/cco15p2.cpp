/*
CCO '15 P2 - Artskjid
Key Concepts: Dynamic Programming (bitmask)
https://dmoj.ca/problem/cco15p2
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 18; 

struct Edge{int n, w;};

int ans;
int nodes, edges; 
vector<Edge> adj[MAXN];
int dist[(1<<MAXN)][MAXN];

// set dth bit of n
int setb(int n, int d) {
    return n | (1 << d);
}

// n = current node, c = current state
void solve(int n, int c) {
    // reached end
    if (n == nodes-1) {
        ans = max(ans, dist[c][n]);
        return;
    }

    // traverse graph
    for (Edge e : adj[n]) {
        int t = setb(c, e.n);   // next state
        if (t != c && dist[c][n] + e.w > dist[t][e.n]) {
            dist[t][e.n] = dist[c][n] + e.w;
            solve(e.n, t);
        }
    }
}

int main() {
    fio;

    // init
    cin >> nodes >> edges;
    int a, b, w;
    for (int i = 0; i < edges; i++) {
        cin >> a >> b >> w;
        adj[a].pb({b,w});
    }

    // dp
    solve(0, 1);

    cout << ans << "\n";

    return 0;
}