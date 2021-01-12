/*
AtCoder Beginner Contest 188 Problem B - Orthogonality 
Key Concepts: Implementation
https://atcoder.jp/contests/abc188/tasks/abc188_b
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int ans = 0;
    int n, x; cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        ans += q.front() * x;
        q.pop();
    }
    cout << (ans == 0 ? "Yes" : "No") << endl;

    return 0;
}