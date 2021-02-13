/*
DMOPC '15 Contest 1 P6 - Lelei and Contest
Key Concepts: Data Structures (segment tree w/ lazy propagation), Intermediate Math (Fermat's Little Theorem)
https://dmoj.ca/problem/dmopc15c1p6
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define m (l+r)/2
#define lc n+1
#define rc n+2*(m-l+1)

const int MAXN = 2e5+5; 

int M, N, Q;
int arr[MAXN];
int st[2*MAXN];
int lazy[2*MAXN];

inline int add(int a, int b) {
    return (a+b)%M;
}

inline int mul(int a, int b) {
    return ((long long)(a%M)*(long long)(b%M))%M;
}

inline void init(int n, int val) {
    st[n] = val;
}

inline int merge(int l, int r) {
    return add(l, r);
}

void build(int n, int l, int r) {
    if (l == r) {
        init(n, arr[l]);
        return;
    }
    build(lc, l, m);
    build(rc, m+1, r);
    st[n] = merge(st[lc], st[rc]);
}

void push(int n, int l, int r) {
    st[n] = add(st[n], mul(lazy[n], r-l+1));
    lazy[lc] = add(lazy[lc], lazy[n]);
    lazy[rc] = add(lazy[rc], lazy[n]);
    lazy[n] = 0;
}

void update(int n, int l, int r, int ql, int qr, int val) {
    if (r < ql || qr < l) return;
    if (l == ql && qr == r) {
        lazy[n] = add(lazy[n], val);
        return;
    }
    st[n] = add(st[n], mul(val, qr-ql+1));
    if (lazy[n]) push(n, l, r);
    update(lc, l, m, ql, min(qr, m), val);
    update(rc, m+1, r, max(ql, m+1), qr, val);
}

int query(int n, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (l == ql && qr == r) return add(st[n], mul(lazy[n], r-l+1));
    if (lazy[n]) push(n, l, r);
    return merge(query(lc, l, m, ql, min(qr, m)), query(rc, m+1, r, max(ql, m+1), qr));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> M >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i] %= M;
    }

    build(1, 1, N);

    int op, l, r, x;
    while (Q--) {
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> x;
            update(1, 1, N, l, r, x);
        }
        else {
            cout << query(1, 1, N, l, r) << '\n';
        }
    }

    return 0;
}