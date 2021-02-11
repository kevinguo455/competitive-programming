/*
DMOPC '15 Contest 1 P6 - Lelei and Contest
Key Concepts: 
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
    lazy[l] += lazy[n];
    lazy[r] += lazy[n];
    lazy[n] = 0;
}

void update(int n, int l, int r, int ql, int qr, int val) {
    if (r < ql || qr < l) return;
    if (l == ql && qr == r) {
        lazy[n] += val;
        return;
    }
    push(n, lc, rc);
    
}

int query(int n, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (l == ql && qr == r) return st[n];
    return merge(query(lc, l, m, ql, min(qr, m)), query(rc, m+1, r, max(ql, m+1), qr));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> M >> N >> Q;
    for (int i = 0; i < N; i++) cin >> arr[i];

    build(1, 1, N);

    int op, l, r, x;
    while (Q--) {
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> x;
        }
        else {
            
        }
    }

    return 0;
}