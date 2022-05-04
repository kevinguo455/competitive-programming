/*
Another Contest 7 Problem 3 - Network Connections
Key Concepts: Minimum Spanning Tree (Kruskal's), Line Sweep 
https://dmoj.ca/problem/acc7p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+5; 

struct User {
    int n, f;
    bool operator<(const User &u) {return f < u.f;}
};

struct Edge {
    int a, b, w;
    bool operator<(const Edge &e) {return w < e.w;}
};

int N, M;
int parent[MAXN], height[MAXN];
vector<User> users;
vector<Edge> edges;
ll ans;

int Find(int n) {
    if (parent[n] == 0 || parent[n] == n) return n;
    return parent[n] = Find(parent[n]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (height[a] < height[b]) swap(a, b);
    else if (height[a] == height[b]) height[a]++;
    parent[b] = a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 1, f; i <= N; i++) {
        cin >> f;
        users.push_back({i, f});
    }
    for (int i = 1, a, b; i <= M; i++) {
        cin >> a >> b;
        Union(a, b);
    }

    sort(users.begin(), users.end());

    for (int i = 1; i < N; i++) {
        edges.push_back({users[i-1].n, users[i].n, users[i].f-users[i-1].f});
    }

    sort(edges.begin(), edges.end());
    
    for (Edge e : edges) {
        if (Find(e.a) == Find(e.b)) continue;
        ans += e.w;
        Union(e.a, e.b);
    }

    cout << ans << '\n';

    return 0;
}