/*
Connected Components
Key Concepts: Disjoint Set Union
https://dmoj.ca/problem/graph2p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define int short

const int MAXN = 1001;

int parent[MAXN];
//int height[MAXN];
vector<int> component[MAXN];

int find_set(int n) {
    if (parent[n] == 0 || parent[n] == n) return n;
    return parent[n] = find_set(parent[n]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (b < a) swap(a, b);
    //if (height[a] < height[b]) swap(a, b);
    //else if (height[a] == height[b]) height[a]++;
    parent[b] = a;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    bool e;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> e;
            if (e) union_set(i, j);
        }
    }

    for (int i = 1; i <= n; i++) {
        component[find_set(i)].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j : component[i]) cout << j << " ";
        if (component[i].size()) cout << "\n";
    }

    return 0;
}