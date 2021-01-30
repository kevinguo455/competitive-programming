/*
Mynerva
Key Concepts: Graph Theory (Dijkstra's)
https://dmoj.ca/problem/mynerva
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f, MAXN = 5e5+5; 

int N, M, Q;
struct Edge {int n, b;};

vector<Edge> adj[MAXN];
Edge dist1[MAXN];   // min dist with min bright
Edge dist2[MAXN];   // min dist with max bright

bool cmp1(int x, int y) {
    if (dist1[x].n == dist1[y].n)
        return dist1[x].b > dist1[y].b;
    return dist1[x].n > dist1[y].n;
}

bool cmp2(int x, int y) {
    if (dist2[x].n == dist2[y].n)
        return dist2[x].b < dist2[y].b;
    return dist2[x].n > dist2[y].n;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init graph
    cin >> N >> M;
    int x, y, b;
    while (M--) {
        cin >> x >> y >> b;
        adj[x].push_back({y, b});
        adj[y].push_back({x, b});
    }
    for (int i = 1; i <= N; i++) {
        dist1[i] = {INF, INF};
        dist2[i] = {INF, 0};
    }

    // precompute min dist + min bright
    priority_queue<int, vector<int>, function<bool(int, int)>> pq1(cmp1);
    pq1.push(1);
    dist1[1] = {0, 0};
    while (!pq1.empty()) {
        int c = pq1.top();
        pq1.pop();
        for (Edge t : adj[c]) {
            if (dist1[c].n + 1 < dist1[t.n].n || (dist1[c].n + 1 == dist1[t.n].n && dist1[c].b + t.b < dist1[t.n].b)) {
                dist1[t.n] = {dist1[c].n + 1, dist1[c].b + t.b};
                pq1.push(t.n);
            }
        }
    }

    // precompute min dist + max bright
    priority_queue<int, vector<int>, function<bool(int, int)>> pq2(cmp2);
    pq2.push(1);
    dist2[1] = {0, 0};
    while (!pq2.empty()) {
        int c = pq2.top();
        pq2.pop();
        for (Edge t : adj[c]) {
            if (dist2[c].n + 1 < dist2[t.n].n || (dist2[c].n + 1 == dist2[t.n].n && dist2[c].b + t.b > dist2[t.n].b)) {
                dist2[t.n] = {dist2[c].n + 1, dist2[c].b + t.b};
                pq2.push(t.n);
            }
        }
    }

    // answer queries
    cin >> Q;
    int d;
    string s;
    while (Q--) {
        cin >> d >> s;
        if (s[0] == 'B') cout << dist1[d].n << " " << dist1[d].b << "\n";
        else cout << dist2[d].n << " " << dist2[d].b << "\n";
    }

    return 0;
}