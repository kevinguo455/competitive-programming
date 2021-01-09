/*
CCC '15 J5 - π-day
Key Concepts: Dynamic Programming
https://dmoj.ca/problem/ccc15j5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 251;

int dp[MAXN][MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int mn, mk; cin >> mn >> mk;
    dp[1][1] = 1;

    for (int n = 1; n <= mn; n++) {
        for (int k = 1; k <= min(mk, n); k++) {
            dp[n][k] += dp[n-k][k] + dp[n-1][k-1];  // dp[n-k][k] counts solutions that do not include a 1 (subtract 1 from all elements)        
        }                                           // dp[n-1][k-1] counts solutions that do include a 1 (remove the 1)
    }

    cout << dp[mn][mk] << "\n";

    return 0;
}