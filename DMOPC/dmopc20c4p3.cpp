/*
DMOPC '20 Contest 4 P3 - Roving Roombas
Key Concepts: Coordinate Compression, Line Sweep, Segment Tree
https://dmoj.ca/problem/dmopc20c4p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 4e5+5;

#define m (l+r)/2
#define lc n+1
#define rc n+2*(m-l+1)

struct Event {
    int x, y;
    bool type; // 0 = remove (left-right), 1 = sum (up-down)
};

bool cmpX(Event a, Event b) {
    if (a.x == b.x) return !b.type;
    return a.x < b.x;
}

bool cmpY(Event a, Event b) {
    if (a.y == b.y) return !a.type;
    return a.y < b.y;
}

int st[2*MAXN];

void update(int n, int l, int r, int idx, int val) {
    if (idx == l && idx == r) {
        st[n] = val;
        return;
    }
    if (idx <= m) update(lc, l, m, idx, val);
    else update(rc, m+1, r, idx, val);
    st[n] = st[lc] + st[rc];
}

int query(int n, int l, int r, int ql, int qr) {
    if (ql == l && qr == r) return st[n];
    if (r < ql || qr < l) return 0;
    return query(lc, l, m, ql, min(qr, m)) + query(rc, m+1, r, max(ql, m+1), qr);
}

vector<Event> v;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // read input
    int N, M; cin >> N >> M;
    v.resize(N+M+1);
    for (int i = 1; i <= N; i++) { 
        cin >> v[i].x >> v[i].y;
    }
    for (int i = N+1; i <= N+M; i++) {
        cin >> v[i].x >> v[i].y;
        v[i].type = 1;
    }

    // coordinate compression
    sort(v.begin()+1, v.end(), cmpY);
    for (int i = 1; i < v.size(); i++) {
        v[i].y = i;
    }
    sort(v.begin()+1, v.end(), cmpX);
    for (int i = 1; i < v.size(); i++) {
        v[i].x = i;
    }

    // init segtree
    for (int i = 1; i < v.size(); i++) {
        if (v[i].type == 0) {
            update(1, 1, N+M, v[i].y, 1);
        }
    }

    // line sweep
    ll ans = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].type == 1) {
            ans += (ll) query(1, 1, N+M, 1, v[i].y);
        }
        else {
            update(1, 1, N+M, v[i].y, 0);
        }
    }

    cout << ans << '\n';

    return 0;
}