/*
Appleby Contest '20 P4 - Philosophy Class
Key Concepts: Graph Theory, Implementation
https://dmoj.ca/problem/ac20p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3005; 

struct Edge{
    int a, b;
    void init(int n, int m) {
        a = n;
        b = m;
        if (a > b) swap(a, b);
    }
    bool operator<(const Edge &e) {
        if (a == e.a) return b < e.b;
        return a < e.a;
    }
};

bool cmp(Edge x, Edge y) {
    if (x.a == y.a) return x.b < y.b;
    return x.a < y.a;
}

int N, M;

vector<int> adj[MAXN];
vector<Edge> edges;
int child[MAXN];

bool cycle3(int n, int d, int e) {
    if (d == 3) return n == e;
    if (d == 2 && n == e) return 0;
    for (int t : adj[n]) {
        if (cycle3(t, d+1, e)) {
            child[n] = t;
            return 1;
        }
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    edges.resize(M);
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges[i].init(a, b);
    }
    for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());
    sort(edges.begin(), edges.end());

    // check 3
    for (int i = 1; i <= N; i++) {
        if (cycle3(i, 0, i)) {
            cout << "3\n" << i << ' ' << child[i] << ' ' << child[child[i]] << '\n';
            return 0;
        }
    }

    // check 4
    vector<int> u(4);
    for (int i = 0; i < M; i++) {
        for (int j = 1; j < M; j++) {
            if (edges[i].a != edges[j].a && edges[i].a != edges[j].b && edges[i].b != edges[j].a && edges[i].b != edges[j].b) {
                u[0] = edges[i].a;
                u[1] = edges[i].b;
                u[2] = edges[j].a;
                u[3] = edges[j].b;
                sort(u.begin(), u.end());
                cout << "4\n" << u[0] << ' ' << u[1] << ' ' << u[2] << ' ' << u[3] << '\n';
                return 0;
            }
        }
    }
    
    cout << "-1\n";

    return 0;
}