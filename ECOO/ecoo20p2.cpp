/*
ECOO '20 P2 - Online Shopping
Key Concepts: Greedy Algorithms, Implementation
https://dmoj.ca/problem/ecoo20p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int cases; cin >> cases;
    while (cases--) {
        int N; cin >> N;
        map<string, priority_queue<pii, vector<pii>, greater<pii>>> m;
        string s;
        int p, q;
        while (N--) {
            int M; cin >> M;
            while (M--) {
                cin >> s >> p >> q;
                m[s].push({p, q});
            }
        }
        int Q; cin >> Q;
        int ans = 0;
        while (Q--) {
            cin >> s >> q;
            while (q > m[s].top().se) {
                ans += m[s].top().fi * m[s].top().se;
                q -= m[s].top().se;
                m[s].pop();
            }
            ans += q * m[s].top().fi;
        }
        cout << ans << '\n';
    }

    return 0;
}