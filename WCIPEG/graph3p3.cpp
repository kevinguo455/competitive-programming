/*
Cable TV
Key Concepts: Minimum Spanning Tree
https://dmoj.ca/problem/graph3p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5; 

int parent[MAXN];
int height[MAXN];

int find_set(int n) {
    if (parent[n] == 0 || parent[n] == n) return n;
    return parent[n] = find_set(parent[n]);
}

void union_set(int a, int b) {
    if (height[a] < height[b]) swap(b, a);
    else if (height[a] == height[b]) height[a]++;
    parent[b] = a;
}

struct Edge {
    int a, b, c;
    bool d;

    bool operator<(const Edge e) {
        if (d == e.d) return c < e.c;
        return d < e.d;
    }
};

vector<Edge> edges;

int main() {
    cin.tie(0)->sync_with_stdio(0);


    int N, E; cin >> N >> E;
    int a, b, c; bool d;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c >> d;
        edges.push_back({a, b, c, d});
    }

    sort(edges.begin(), edges.end());

    int danger = 0, cost = 0;

    for (Edge e : edges) {
        a = find_set(e.a);
        b = find_set(e.b);
        if (a != b) {
            union_set(a, b);
            cost += e.c;
            danger += e.d;
        }
    }

    cout << danger << " " << cost << "\n";

    return 0;
}