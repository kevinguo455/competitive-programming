/*
RTE '16 S3 - School Traversal
Key Concepts: Lowest Common Ancestor (Binary Lifting)
https://dmoj.ca/problem/rte16s3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 6001, MAXK = 13; 

struct Edge{int n, w;};

vector<Edge> adj[MAXN];
int in[MAXN], out[MAXN], idx, up[MAXN][MAXK];
ll dist[MAXN];

void dfs(int c, int p) {
    in[c] = idx++;

    up[c][0] = p;
    for (int i = 1; i < MAXK; i++) {
        up[c][i] = up[up[c][i-1]][i-1];
    }

    for (Edge t : adj[c]) {
        if (t.n == p) continue;
        dist[t.n] = dist[c] + t.w;
        dfs(t.n, c);
    }

    out[c] = idx++;
}

bool is_anc(int a, int b) {
    return (in[a] <= in[b] && out[b] <= out[a]);
}

int lca(int a, int b) {
    if (is_anc(a, b)) return a;
    if (is_anc(b, a)) return b;
    for (int i = MAXK-1; i >= 0; i--) {
        if (!is_anc(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // build tree (node 1 is root)
    int N; cin >> N;
    for (int i = 1, a, b, w; i < N; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    // generate in, out, up, and dist arrays
    dfs(0, 0);

    // answer queries
    int Q; cin >> Q;
    for (int i = 0, a, b; i < Q; i++) {
        cin >> a >> b;
        cout << dist[a] + dist[b] - 2 * dist[lca(a, b)] << '\n';
    }

    return 0;
}