/*
CCC '18 S5 - Maximum Strategic Savings
Key Concepts: Graph Theory (Minimum Spanning Tree - Kruskal's)
https://dmoj.ca/problem/ccc18s5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+5; 

ll N, M, P, Q;
ll mst, tot;

struct Edge {
    int a, b, w;
    bool d;     // horizontal = 0, vertical = 1

    bool operator<(const Edge& e) {
        return w < e.w;
    }
};

vector<Edge> edges;

int parent_h[MAXN], rank_h[MAXN];
int parent_v[MAXN], rank_v[MAXN];

int find_parent(int n, int parent[]) {
    if (parent[n] == 0 || parent[n] == n) return n;
    return parent[n] = find_parent(parent[n], parent);
}

void union_set(int a, int b, int parent[], int rank[]) {
    if (rank[a] < rank[b]) swap(a, b);
    else if (rank[a] == rank[b]) rank[a]++;
    parent[b] = a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> P >> Q;

    int a, b, w;
    for (int i = 0; i < P; i++) {
        cin >> a >> b >> w;
        edges.push_back({a, b, w, 0});
        tot += w * N;
    }
    for (int i = 0; i < Q; i++) {
        cin >> a >> b >> w;
        edges.push_back({a, b, w, 1});
        tot += w * M;
    }

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (e.d) {
            a = find_parent(e.a, parent_h);
            b = find_parent(e.b, parent_h);
            if (a != b) {
                union_set(a, b, parent_h, rank_h);
                mst += e.w * M;
                N--;
            }
        }
        else {
            a = find_parent(e.a, parent_v);
            b = find_parent(e.b, parent_v);
            if (a != b) {
                union_set(a, b, parent_v, rank_v);
                mst += e.w * N;
                M--;
            }
        }
    }   

    cout << tot - mst << '\n';

    return 0;
}