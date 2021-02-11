/*
DMOPC '19 Contest 6 P4 - Grade 12 Math
Key Concepts: Data Structures (Segment Tree, Map)
https://dmoj.ca/problem/dmopc19c6p4hard
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define left_child(n, l, m) n+1
#define right_child(n, l, m) n + 2*(m-l+1)

const int MAXN = 5e5+5; 

map<int, int> st[2*MAXN];
int arr[MAXN];

void build(int n, int l, int r) {
    st[n][0] = r-l+1;
    if (l == r) return;

    int m = (l+r)/2;
    build(left_child(n, l, m), l, m);
    build(right_child(n, l, m), m+1, r);
}

void update(int n, int l, int r, int idx, int val) {
    if (st[n][arr[idx]] == 1) st[n].erase(arr[idx]);
    else st[n][arr[idx]]--;
    st[n][arr[idx] + val]++;
    if (l == r) {
        arr[idx] += val;
        return;
    }

    int m = (l+r)/2;
    if (idx <= m) update(left_child(n, l, m), l, m, idx, val);
    else update(right_child(n, l, m), m+1, r, idx, val);
}

int query(int n, int l, int r, int ql, int qr, int val) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) {
        if (st[n].find(val) == st[n].end()) return 0;
        return st[n][val];
    }
    int m = (l+r)/2;
    return query(left_child(n, l, m), l, m, ql, min(qr, m), val) + query(right_child(n, l, m), m+1, r, max(ql, m+1), qr, val);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q; cin >> N >> Q;

    build(1, 1, N);

    int op, l, r, x;
    while (Q--) {
        cin >> op;
        if (op == 1) {
            cin >> x;
            update(1, 1, N, x, 1);
        }
        else if (op == 2) {
            cin >> x;
            update(1, 1, N, x, -1);
        }
        else if (op == 3) {
            cin >> l >> r >> x;
            cout << query(1, 1, N, l, r, x) << '\n';
        }
    }

    return 0;
}