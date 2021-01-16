/*
Troubling Times
Key Concepts: Implementation
https://dmoj.ca/problem/anct1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f; 

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, t; cin >> n >> t;
    t = abs(t);

    int x, ans = INF;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (t % x == 0) {
            ans = min(ans, t / x);
        }
    }

    if (ans == INF) cout << "This is not the best time for a trip.\n";
    else cout << ans << "\n";

    return 0;
}