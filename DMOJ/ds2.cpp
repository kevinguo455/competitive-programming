/*
Disjoint Set Test
Key Concepts: Data Structures (Disjoint Set)
https://dmoj.ca/problem/ds2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5; 

int parent[MAXN];
int height[MAXN];

int find_set(int n) {
    if (parent[n] == 0) return n;
    return parent[n] = find_set(parent[n]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (height[a] < height[b]) swap(a, b);
    parent[b] = a;
    if (height[a] == height[b]) height[a]++;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, cnt = 1; cin >> N >> M;
    int a, b;
    queue<int> q;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        if (find_set(a) != find_set(b)) {
            q.push(i);
            union_set(a, b);
            cnt++;
        }
    }
    if (cnt != N) cout << "Disconnected Graph\n";
    else {
        while (!q.empty()) {
            cout << q.front() << "\n";
            q.pop();
        }
    }

    return 0;
}