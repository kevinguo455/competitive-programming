/*
Segment Tree Test
Key Concepts: Data Structures (Segment Tree)
https://dmoj.ca/problem/ds3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f, MAXN = 1e5+5; 

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int N, M;
int arr[MAXN];

struct Node {
    int m, g, f;

    void init(int n) {
        m = n;
        g = n;
        f = 1;
    }

    void merge(Node a, Node b) {
        if (a.m == INF) {
            copy(b);
            return;
        }
        if (b.m == INF) {
            copy(a);
            return;
        }
        m = min(a.m, b.m);
        g = gcd(a.g, b.g);
        f = 0;
        if (m == g) {
            if (m == a.m) f += a.f;
            if (m == b.m) f += b.f;
        }
    }

    void copy(Node n) {
        m = n.m;
        g = n.g;
        f = n.f;
    }

};

Node st[MAXN*4];

void build(int n, int l, int r) {
    if (l == r) {
        st[n].init(arr[l]);
    }
    else {
        int m = (l+r)/2;
        build(2*n, l, m);
        build(2*n+1, m+1, r);
        st[n].merge(st[2*n], st[2*n+1]);
    }
}

void update(int n, int l, int r, int idx, int val) {
    if (l == idx && r == idx) {
        st[n].init(val);
        return;
    }
    int m = (l+r)/2;
    if (idx <= m) {
        update(2*n, l, m, idx, val);
    }
    else {
        update(2*n+1, m+1, r, idx, val);
    }
    st[n].merge(st[2*n], st[2*n+1]);
}

Node query(int n, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return st[n];
    }
    Node res;
    if (qr < l || r < ql) {
        res.init(INF);
        return res;
    }
    int m = (l+r)/2;
    res.merge(query(n*2, l, m, ql, min(m, qr)), query(n*2+1, m+1, r, max(m+1, ql), qr));
    return res;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    build(1, 0, N-1);

    char op;
    int l, r;
    for (int i = 0; i < M; i++) {
        cin >> op >> l >> r;
        l--;

        if (op == 'C') {
            update(1, 0, N-1, l, r);
        }
        else {
            r--;
            Node ans = query(1, 0, N-1, l, r);
            if (op == 'M') {
                cout << ans.m << "\n";
            }
            else if (op == 'G') {
                cout << ans.g << "\n";
            }
            else if (op == 'Q') {
                cout << ans.f << "\n";
            }
        }
    }

    return 0;
}