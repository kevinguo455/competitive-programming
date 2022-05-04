/*
BSSPC '21 J6 - Lakshy and Orz Trees
Key Concepts: Graph Theory, Dynamic Programming
https://dmoj.ca/problem/bsspc21j6
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5+5; 

int cost[MAXN]; ll cut[MAXN];
vector<int> adj[MAXN];

struct Node{ll delta, cut, keep;};

bool cmp(Node a, Node b) {
    return a.delta > b.delta;
}

void dfs_init_cut(int c, int p) {
    for (int t : adj[c]) {
        if (t != p) dfs_init_cut(t, c);
    }
    cut[c] += cost[c];
    cut[p] += cut[c];
}

ll dfs_solve(int c, int p) {
    ll ret = 0;

    vector<Node> v;
    for (int t : adj[c]) {
        if (t != p) {
            v.push_back({0, cut[t], dfs_solve(t, c)});
            v.back().delta = v.back().cut - v.back().keep;
        }
    }
    sort(v.begin(), v.end(), cmp);

    int i = 0;
    if (c == 1) {
        for (; i < min(3, (int)v.size()); i++) {
            if (v[i].delta > 0) ret += v[i].keep;
            else ret += v[i].cut;
        }
    }
    else {
        for (; i < min(2, (int)v.size()); i++) {
            if (v[i].delta > 0) ret += v[i].keep;
            else ret += v[i].cut;
        }
    }
    
    for (; i < (int)v.size(); i++) {
        ret += v[i].cut;
    }

    return ret;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    for (int i = 2; i <= N; i++) cin >> cost[i];
    for (int i = 2, a, b; i <= N; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_init_cut(1, 1);
    cut[1] = 0;

    cout << dfs_solve(1, 1) << '\n';

    return 0;
}