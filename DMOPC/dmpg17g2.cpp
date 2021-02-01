/*
DMPG '17 G2 - Holy Grail War
Key Concepts: Data Structures (Segment Tree)
https://dmoj.ca/problem/dmpg17g2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+5; 

inline ll max3(ll a, ll b, ll c) {
    return max(a, max(b, c));
}

struct Node {
    ll any;
    ll pre;
    ll suf;
    ll all;

    void init(ll n) {
        any = n;
        pre = n;
        suf = n;
        all = n;
    }

    void merge(Node a, Node b) { 
        any = max3(a.any, b.any, a.suf + b.pre);
        pre = max(a.pre, a.all + b.pre);
        suf = max(b.suf, b.all + a.suf);
        all = a.all + b.all;
    }
};

int arr[MAXN];
Node st[4*MAXN];

void build(int n, int l, int r) {
    if (l == r) {
        st[n].init(arr[l]);
        return;
    }
    int m = (l+r)/2;
    build(2*n, l, m);
    build(2*n+1, m+1, r);
    st[n].merge(st[2*n], st[2*n+1]);
}

void update(int n, int l, int r, int idx, int val) {
    if (l == idx && r == idx) {
        st[n].init(val);
        return;
    }
    int m = (l+r)/2;
    if (idx <= m) update(2*n, l, m, idx, val);
    else update(2*n+1, m+1, r, idx, val);
    st[n].merge(st[2*n], st[2*n+1]);
}

Node query(int n, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return st[n];
    
    int m = (l+r)/2;
    if (qr <= m) return query(2*n, l, m, ql, min(qr, m));
    if (ql > m) return query(2*n+1, m+1, r, max(m+1, ql), qr);

    Node res;
    res.merge(query(2*n, l, m, ql, min(qr, m)), query(2*n+1, m+1, r, max(m+1, ql), qr));
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    build(1, 1, N);
    
    char op;
    int a, b;
    while (Q--) {
        cin >> op >> a >> b;
        if (op == 'S') {
            update(1, 1, N, a, b);
        }
        else {
            cout << query(1, 1, N, a, b).any << "\n";
        }
    }

    return 0;
}