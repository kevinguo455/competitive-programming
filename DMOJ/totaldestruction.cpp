/*
Total Destruction
Key Concepts: Greedy Algorithms, Implementation
https://dmoj.ca/problem/totaldestruction
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<int> v, s;    
    int n, m, q; cin >> n >> m >> q;
    int x;
    for (int i = 0; i < q; i++) {
        cin >> x;
        v.pb(x);
    }
    vs(v);
    for (int i = 1; i < q; i++) {
        s.pb(v[i]-v[i-1]-1);
    }
    vs(s);
    vr(s);

    int ans = v[q-1]-v[0]+1;
    for (int i:s) {
        m--;
        if (!m) break;
        ans -= i;
    }
    cout << ans << "\n";

    return 0;
}