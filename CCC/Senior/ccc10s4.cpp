/*
CCC '10 S4 - Animal Farm
Key Concepts: Minimum Spanning Tree
https://dmoj.ca/problem/ccc10s4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;

const int MAXN = 1001; 

int parent[MAXN];
int height[MAXN];

int find_set(int n) {
    if (parent[n] == 0x3f3f3f3f || parent[n] == n) return n;
    return parent[n] = find_set(parent[n]);
}

void union_set(int a, int b) {
    if (height[a] < height[b]) swap(a, b);
    else if (height[a] == height[b]) height[a]++;
    parent[b] = a;
}

pii dual[MAXN][MAXN];
bool added[MAXN][MAXN];

struct Edge {
    int a, b, w;
    bool operator<(const Edge e) {
        return w < e.w;
    }
};
vector<Edge> edges;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            dual[i][j].se = -1;
        }
    }

    int P; cin >> P;
    for (int a = 1; a <= P; a++) {
        int n; cin >> n;
        pii e[n+1];
        for (int i = 0; i < n; i++) cin >> e[i].fi;
        for (int i = 0; i < n; i++) cin >> e[i].se;
        e[n] = e[0];
        
        for (int i = 0; i < n; i++) {
            if (dual[e[i].fi][e[i+1].fi].se != -1) {
                edges.push_back({a, dual[e[i].fi][e[i+1].fi].fi, e[i].se});
                added[e[i].fi][e[i+1].fi] = 1;
                added[e[i+1].fi][e[i].fi] = 1;
            }
            else {
                dual[e[i].fi][e[i+1].fi] = {a, e[i].se};
                dual[e[i+1].fi][e[i].fi] = {a, e[i].se};
            }
        }
    }

    sort(edges.begin(), edges.end());
    memset(parent, 0x3f, sizeof parent);

    int ans1 = 0, cnt = 0; 
    for (Edge e : edges) {
        int a = find_set(e.a);
        int b = find_set(e.b);
        if (a != b) {
            union_set(a, b);
            ans1 += e.w;
            cnt++;
        }
    }

    if (cnt != P-1) ans1 = 0x3f3f3f3f;

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < i; j++) {
            if (!added[i][j] && dual[i][j].se != -1) {
                edges.push_back({0, dual[i][j].fi, dual[i][j].se});
            }
        }
    }

    sort(edges.begin(), edges.end());
    memset(parent, 0x3f, sizeof parent);
    memset(height, 0, sizeof height);

    int ans2 = 0;
    for (Edge e : edges) {
        int a = find_set(e.a);
        int b = find_set(e.b);
        if (a != b) {
            union_set(a, b);
            ans2 += e.w;
        }
    }
    cout << min(ans1, ans2) << "\n";

    return 0;
}