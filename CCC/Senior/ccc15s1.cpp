/*
CCC '15 S1 - Zero That Out
Key Concepts: Implementation
https://dmoj.ca/problem/ccc15s1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    stack<int> q;
    while (N--) {
        int x; cin >> x;
        if (x == 0) q.pop();
        else q.push(x);
    }

    int ans = 0;
    while (!q.empty()) {
        ans += q.top();
        q.pop();
    }

    cout << ans << '\n';

    return 0;
}