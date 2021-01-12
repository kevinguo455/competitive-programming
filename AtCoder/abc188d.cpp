/*
AtCoder Beginner Contest 188 Problem D - Snuke Prime 
Key Concepts: Difference Array, Coordinate Compression
https://atcoder.jp/contests/abc188/tasks/abc188_d
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 4e5+5;

ll diff[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; ll s; cin >> n >> s;
    int a, b, c;

    // coordinate compression
    set<int> vals;
    queue<int> aq, bq, cq;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        vals.insert(a-1);
        vals.insert(b);     // 1-indexed
        aq.push(a-1);
        bq.push(b);
        cq.push(c);
    }
    unordered_map<int, int> m, mr;
    int idx = 0;
    for (int n : vals) {
        m[n] = idx;
        mr[idx] = n;
        idx++;
    }

    // difference array
    for (int i = 0; i < n; i++) {
        a = aq.front(); aq.pop();
        b = bq.front(); bq.pop();
        c = cq.front(); cq.pop();
        diff[m[a]] += c;
        diff[m[b]] -= c;
    }

    // flatten
    ll ans = 0;
    for (int i = 0; i < idx; i++) {
        diff[i+1] += diff[i];
        ans += min(diff[i], s) * (ll)(mr[i+1]-mr[i]);
    }
    cout << ans << "\n";

    return 0;
}