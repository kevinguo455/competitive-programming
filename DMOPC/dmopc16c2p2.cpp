/*
DMOPC '16 Contest 2 P2 - Ebola Outbreak
Key Concepts: Data Structures (Disjoint Set Union)
https://dmoj.ca/problem/dmopc16c2p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5; 

int parent[MAXN];
int height[MAXN];

int find_set(int n) {
    if (parent[n] == n || parent[n] == 0) return n;
    return parent[n] = find_set(parent[n]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (height[a] < height[b]) swap(a, b);
    else if (height[a] == height[b]) height[a]++;
    parent[b] = a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;
    while (M--) {
        int C; cin >> C;
        int r; cin >> r; C--;
        while (C--) {
            int x; cin >> x;
            union_set(r, x);
        }
    }

    int r = find_set(1);
    queue<int> q; q.push(1);
    for (int i = 2; i <= N; i++) {
        if (find_set(i) == r) q.push(i);
    }

    cout << q.size() << '\n';
    while (!q.empty()) {
        cout << q.front() << ' '; q.pop();
    }
    cout << '\n';

    return 0;
}