/*
AtCoder Educational DP Contest Problem L - Deque
Key Concepts: Dynamic Programming (intervals), Greedy Algorithms (turn-based)
https://dmoj.ca/problem/dpl
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 3005;

ll dp[MAXN][MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    // state: optimal score for player 1 if the game only had elements from l to r
    int n; cin >> n;
    cin >> dp[0][0];
    ll s = dp[0][0];

    // all 2-turn states (interval [a, a] or [a, a+1], inclusive)
    for (int i = 1; i < n; i++) {
        cin >> dp[i][i];
        dp[i-1][i] = max(dp[i-1][i-1], dp[i][i]);
        s += dp[i][i];
    }

    // all states of length l (interval [a, a+l], inclusive)
    for (int l = 2; l < n; l++) {
        for (int a = 0; a < n-l; a++) {
            dp[a][a+l] = max(dp[a][a] + min(dp[a+1][a+l-1], dp[a+2][a+l]), dp[a+l][a+l] + min(dp[a][a+l-2], dp[a+1][a+l-1]));
        }
    }

    // max difference = score1 - score2 = score1 - (total - score1) = 2 * score1
    cout << 2*dp[0][n-1] - s << endl;

    return 0;
}