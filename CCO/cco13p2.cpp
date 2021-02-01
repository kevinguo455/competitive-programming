/*
CCO '13 P2 - Tourney
Key Concepts: Data Structures (Segment Tree)
https://dmoj.ca/problem/cco13p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f, MAXN = (1 << 20) + 2; 

int N, M, T;
int arr[MAXN];
int wins[MAXN];

struct Node {
    int id, s;

    void init(int a, int b, int h) {
        id = a;
        s = b;
        wins[a] = h;
    }

    void merge(Node a, Node b, int h) {
        if (a.s > b.s) {
            s = a.s;
            id = a.id;
            wins[a.id] = h;
            wins[b.id] = h-1;
        }
        else {
            s = b.s;
            id = b.id;
            wins[b.id] = h;
            wins[a.id] = h-1;
        }
    }
};

Node st[MAXN*4];

void build(int n, int l, int r, int h) {
    if (l == r) {
        st[n].init(l, arr[l], h);
    }
    else {
        int m = (l+r)/2;
        build(2*n, l, m, h-1);
        build(2*n+1, m+1, r, h-1);
        st[n].merge(st[2*n], st[2*n+1], h);
    }
}

void update(int n, int l, int r, int h, int idx, int val) {
    if (l == idx && r == idx) {
        st[n].init(idx, val, h);
        return;
    }
    int m = (l+r)/2;
    if (idx <= m) {
        update(2*n, l, m, h-1, idx, val);
    }
    else {
        update(2*n+1, m+1, r, h-1, idx, val);
    }
    st[n].merge(st[2*n], st[2*n+1], h);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    T = 1 << N;
    for (int i = 1; i <= T; i++) {
        cin >> arr[i];
    }

    build(1, 1, T, N);

    char op;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> op;

        if (op == 'R') {
            cin >> a >> b;
            update(1, 1, T, N, a, b);
        }
        else if (op == 'W') {
            cout << st[1].id << "\n";
        }
        else if (op == 'S') {
            cin >> a;
            cout << wins[a] << "\n";
        }
    }

    return 0;
}