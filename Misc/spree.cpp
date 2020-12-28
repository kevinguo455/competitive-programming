/*
Coding Spree
Key Concepts: Dynamic Progrmaming (0-1 Knapsack)
https://dmoj.ca/problem/spree
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int main() {

    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int n, mw, v, w; cin >> n >> mw;
    for (int i = 0; i < n; i++) {
        cin >> v >> w;
        for (int i = mw; i >= w; i--) {
            dp[i] = max(dp[i], dp[i-w] + v);
        }
    }
    cout << dp[mw] << "\n";

    return 0;
}