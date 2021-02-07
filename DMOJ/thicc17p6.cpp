/*
THICC '17 P6 - Tunnels
Key Concepts: Graph Theory
https://dmoj.ca/problem/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = (int)a; i < (int)b; i++)
#define fr(i,b,a) for (int i = (int)b; i > (int)a; i--)
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
#define fi first
#define se second
#define fio cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 2e5+5; 

struct Edge{int n, w;};

vector<Edge> adj[MAXN];
bool vis[MAXN];
int dist1[MAXN], dist2[MAXN];   // distance to farthest node from each node of graph
queue<int> q;
int maxd;
int n1, n2;     // two diametrically opposed nodes

void dfs(int n, int d) {
    vis[n] = 1;
    if (d > maxd) {
        maxd = d;
        n1 = n;
    }
    for (Edge t:adj[n]) {
        if (vis[t.n] == 0) {
            dfs(t.n, d + t.w);
        }
    }
}

void dfs2(int n, int dist[]) {
    vis[n] = 1;
    for (Edge t:adj[n]) {
        if (vis[t.n] == 0) {
            dist[t.n] = dist[n] + t.w;
            dfs2(t.n, dist);
        }
    }
}

int main() {
    fio;

    // init
    int n, t; cin >> n >> t;
    int a, b, c;
    int d = 0; // total distance in graph
    f(i,1,n) {
        cin >> a >> b >> c;
        adj[a].pb({b,c});
        adj[b].pb({a,c});
        d += c;
    }
    ms(vis, 0);
    d <<= 1;
    
    // find all tunnels with t connecting paths
    f(i,1,n+1) {
        if ((int)adj[i].size() == t) {
            q.push(i);
        }
    }

    // find two diametrically opposed nodes
    dfs(1, 0);
    n2 = n1;
    maxd = 0;
    ms(vis, 0);
    dfs(n2, 0);

    // find distance from those two nodes to every point in graph
    ms(vis, 0);
    dfs2(n1, dist1);
    ms(vis, 0);
    dfs2(n2, dist2);

    // find maximum distance from each point to corner of graph
    f(i,1,n+1) {
        dist1[i] = max(dist1[i], dist2[i]);
    }

    // answer queries
    while (!q.empty()) {
        cout << q.front() << " " << d - dist1[q.front()] << "\n";
        q.pop();
    }

    return 0;
}