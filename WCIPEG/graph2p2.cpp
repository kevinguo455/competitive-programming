/*
Directed Acyclic Graph
Key Concepts: Cycle Detection (Disjoint Set Union)
https://dmoj.ca/problem/graph2p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;

int parent[MAXN];

// no path compression
int find_set(int n) {
    if (parent[n] == 0 || parent[n] == n) return n;
    return parent[n];
}

// no sorting by rank/size
void union_set(int a, int b) {
    parent[b] = a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    bool e;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> e;
            if (e) {
                int a = find_set(i);
                int b = j;
                if (a == b) {
                    cout << "NO\n";
                    return 0;
                }
                union_set(a, b);
            }
        }
    }
    cout << "YES\n";
    return 0;
}