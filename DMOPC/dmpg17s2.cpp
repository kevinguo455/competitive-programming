/*
DMPG '17 S2 - Anime Conventions
Key Concepts: Data Structures (Disjoint Set)
https://dmoj.ca/problem/dmpg17s2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

int parent[MAXN];
int size[MAXN];

void Init(int n) {
    parent[n] = n;
    size[n] = 1;
}

int Find(int n) {
    if (parent[n] == n) return n;
    return parent[n] = Find(parent[n]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; i++) Init(i);

    char op; int x, y;
    while (Q--) {
        cin >> op >> x >> y;
        if (op == 'A') Union(x, y);
        else cout << (Find(x) == Find(y) ? 'Y' : 'N') << "\n";
    }

    return 0;
}