/*
Dynamic Range Minimum Test
Key Concepts: Data Structures (segment tree)
https://dmoj.ca/problem/segtree
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f, MAXN = 1e5+5;

int v[MAXN];
int t[MAXN<<2];

void build(int idx, int l, int r) {
    if (l == r) t[idx] = v[l];
    else {
        int m = (l+r)/2;
        build(idx*2, l, m);
        build(idx*2+1, m+1, r);
        t[idx] = min(t[idx*2], t[idx*2+1]);
    }
}

int query(int idx, int tl, int tr, int l, int r) {
    if (l > r) return INF;
    if (tl == l && tr == r) return t[idx];
    int tm = (tl+tr)/2;
    return min(query(idx*2, tl, tm, l, min(r, tm)), query(idx*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int idx, int tl, int tr, int pos, int x) {
    if (tl == tr) t[idx] = x;
    else {
        int tm = (tl+tr)/2;
        if (pos <= tm) update(idx*2, tl, tm, pos, x);
        else update(idx*2+1, tm+1, tr, pos, x);
        t[idx] = min(t[idx*2], t[idx*2+1]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init array
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // build segtree
    build(1, 0, n-1);

    // operations
    char op;
    int x, y;
    for (int i = 0; i < q; i++) {
        cin >> op >> x >> y;
        if (op == 'M') update(1, 0, n-1, x, y);
        else cout << query(1, 0, n-1, x, y) << "\n";
    }

    return 0;
}