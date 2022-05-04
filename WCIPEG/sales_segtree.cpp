/*
Sales
Key Concepts: (memory optimized) Segment Tree, 0-1 Knapsack
https://dmoj.ca/problem/sales
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e4+5, MAXB = 51; 

int B, N, Q;
int w[MAXN];
int v[MAXN];

struct Knapsack {
    int dp[MAXB];

    Knapsack() {
        memset(dp, 0, sizeof dp);
    }

    void init(int w, int v) {
        memset(dp, 0, sizeof dp);

        for (int i = w; i <= B; i++) {
            dp[i] = v;
        }
    }

    void merge(Knapsack l, Knapsack r) {
        memset(dp, 0, sizeof dp);
    
        for (int i = 0; i <= B; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i] = max(dp[i], l.dp[j] + r.dp[i-j]);
            }
        }
    }
};

// 4N memory segtree does not fit within constraints
Knapsack st[2*MAXN];

int left_child(int n, int l, int m) {
    return n+1;
}

int right_child(int n, int l, int m) {
    return n + 2*(m-l+1);
}

void build(int n, int l, int r) {
    if (l == r) {
        st[n].init(w[l], v[l]);
        return;
    }
    int m = (l+r)/2;
    int lc = left_child(n, l, m);
    int rc = right_child(n, l, m);
    build(lc, l, m);
    build(rc, m+1, r);
    st[n].merge(st[lc], st[rc]);
}

void update(int n, int l, int r, int idx, int val) {
    if (l == idx && r == idx) {
        st[n].init(val, v[idx]);
        return;
    }
    if (idx < l || r < idx) return;

    int m = (l+r)/2;
    int lc = left_child(n, l, m);
    int rc = right_child(n, l, m);
    update(lc, l, m, idx, val);
    update(rc, m+1, r, idx, val);
    st[n].merge(st[lc], st[rc]);
}

Knapsack query(int n, int l, int r, int ql, int qr) {
    Knapsack res;
    if (l == ql && qr == r) {
        return st[n];
    }
    if (qr < l || r < ql) {
        return res;
    }
    int m = (l+r)/2;
    int lc = left_child(n, l, m);
    int rc = right_child(n, l, m);
    res.merge(query(lc, l, m, ql, min(qr, m)), query(rc, m+1, r, max(ql, m+1), qr));
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> B >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    build(1, 1, N);

    int a, b, x, y;
    while (Q--) {
        cin >> a >> b >> x >> y;
        update(1, 1, N, a, b);
        cout << query(1, 1, N, x, y).dp[B] << '\n';
    }

    return 0;
}