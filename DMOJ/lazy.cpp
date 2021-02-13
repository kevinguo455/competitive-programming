/*
Strict Evaluation
Key Concepts: Data Structures (segment tree w/ lazy propagation)
https://dmoj.ca/problem/lazy
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define mid (l+r)/2
#define left_child n+1
#define right_child n+2*(m-l+1)
typedef long long ll;

const int MAXN = 1e5+5; 

int arr[MAXN];
ll st[2*MAXN];
ll inc[2*MAXN];
int eql[2*MAXN];

int N, Q;

inline void init(int n, int val) {
    st[n] = val;
}

inline ll eval(int n) {
    if (eql[n] != -1) return eql[n] + inc[n];
    return st[n] + inc[n];
}

inline ll merge(int lc, int rc) {
    return min(eval(lc), eval(rc));
}

void push(int n, int l, int r) {
    int m = mid;
    int lc = left_child;
    int rc = right_child;
    if (eql[n] != -1) {
        st[n] = eql[n];
        eql[lc] = eql[n];
        eql[rc] = eql[n];
        eql[n] = -1;
        inc[lc] = 0;
        inc[rc] = 0;
    }
    if (inc[n] != 0) {
        st[n] += inc[n];
        inc[lc] += inc[n];
        inc[rc] += inc[n];
        inc[n] = 0;
    }
}

void build(int n, int l, int r) {
    eql[n] = -1;
    if (l == r) {
        init(n, arr[l]);
        return;
    }
    int m = mid;
    int lc = left_child;
    int rc = right_child;
    build(lc, l, m);
    build(rc, m+1, r);
    st[n] = merge(lc, rc);
}

void range_eql(int n, int l, int r, int ql, int qr, int val) {
    if (r < ql || qr < l) return;
    if (ql == l && r == qr) {
        inc[n] = 0;
        eql[n] = val;
        return;
    }
    push(n, l, r);
    int m = mid;
    int lc = left_child;
    int rc = right_child;
    range_eql(lc, l, m, ql, min(qr, m), val);
    range_eql(rc, m+1, r, max(ql, m+1), qr, val);
    st[n] = merge(lc, rc);
}

void range_inc(int n, int l, int r, int ql, int qr, int val) {
    if (r < ql || qr < l) return;
    if (ql == l && r == qr) {
        inc[n] += val;
        return;
    }
    push(n, l, r);
    int m = mid;
    int lc = left_child;
    int rc = right_child;
    range_inc(lc, l, m, ql, min(qr, m), val);
    range_inc(rc, m+1, r, max(ql, m+1), qr, val);
    st[n] = merge(lc, rc);
}

ll query(int n, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 1e18;
    if (ql == l && qr == r) return eval(n);
    push(n, l, r);
    int m = mid;
    int lc = left_child;
    int rc = right_child;
    return min(query(lc, l, m, ql, min(qr, m)), query(rc, m+1, r, max(ql, m+1), qr));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    build(1, 1, N);

    int op, l, r, x;
    while (Q--) {
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> x;
            range_inc(1, 1, N, l, r, x);
        } 
        else if (op == 2) { 
            cin >> x; 
            range_eql(1, 1, N, l, r, x);
        } 
        else {
            cout << query(1, 1, N, l, r) << '\n';
        }
    }

    return 0;
}