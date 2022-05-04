/*
Another Contest 3 Problem 4 - Range Updates and Range Queries
Key Concepts: Data Structures (segment tree w/ lazy propagation), Intermediate Math (arithmetic series)
https://dmoj.ca/problem/acc3p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define c st[n]
const int MAXN = 1e6+5; 

struct Node {
    int l, r, m;
    int lc, rc;
    int sum, lazy;
    void init(int n, int l, int r) {
        (*this).l = l;
        (*this).r = r;
        m = (l+r)/2;
        lc = n+1;
        rc = n+2*(m-l+1);
    }
    int eval() {
        return sum + lazy*((long long)(r-l+2)*(r-l+1)/2);
    }
    void merge();
    void push();
};

Node st[2*MAXN];

void Node::merge() {
    sum = st[lc].eval() + st[rc].eval();
}

void Node::push() {
    st[lc].lazy = lazy;
    st[rc].lazy = lazy;
    st[rc].sum += (st[rc].l-l) * lazy * (st[rc].r-st[rc].l+1);
    lazy = 0;
}

void build(int n, int l, int r) {
    c.init(n, l, r);
    if (l == r) return;
    build(c.lc, l, c.m);
    build(c.rc, c.m+1, r);
}

void update(int n, int ql, int qr, int val) {
    if (c.r < ql || qr < c.l) return;
    if (c.l == ql && c.r == qr) {
        c.lazy += val;
        return;
    }
    c.push();
    st[c.rc].sum += (st[c.rc].l-c.l) * val * (st[c.rc].r-st[c.rc].l+1);
    update(c.lc, ql, min(qr, c.m), val);
    update(c.rc, max(ql, c.m+1), qr, val);
    c.merge();
}

int query(int n, int ql, int qr) {
    if (c.r < ql || qr < c.l) return 0;
    if (c.l == ql && c.r == qr) return c.eval();
    c.push();
    return query(c.lc, ql, min(qr, c.m)) + query(c.rc, max(ql, c.m+1), qr);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q; cin >> N >> Q;

    build(1, 1, N);

    int op, l, r, x;
    while (Q--) {
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> x;
            update(1, l, r, x);
        }
        else {
            cout << query(1, l, r) << '\n';
        }
    }

    return 0;
}