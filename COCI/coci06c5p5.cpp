/*
COCI '06 Contest 5 #5 Ivana
Key Concepts: Dynamic Programming (interval, game theory)
https://dmoj.ca/problem/coci06c5p5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    int dp[N][N];
    int tot = 0;

    for (int i = 0, x; i < N; i++) {
        cin >> x;
        dp[i][i] = x % 2;
        tot += dp[i][i];
    }

    #define r l+s
    #define m(n) (n+N)%N

    if (N >= 2) {
        for (int l = 0; l < N; l++) {
            dp[l][m(l+1)] = max(dp[l][l], dp[m(l+1)][m(l+1)]);
        }
    }

    for (int s = 2; s + 1 < N; s++) {
        for (int l = 0; l < N; l++) {
            dp[l][m(r)] = max(dp[l][l] + min(dp[m(l+1)][m(r-1)], dp[m(l+2)][m(r)]), dp[m(r)][m(r)] + min(dp[l][m(r-2)], dp[m(l+1)][m(r-1)]));
        }
    }

    tot = tot/2 + 1;
    int ans = 0, s = N-1;
    for (int l = 0; l < N; l++) {
        if (dp[l][l] + min(dp[m(l+1)][m(r-1)], dp[m(l+2)][m(r)]) >= tot) ans++;
    }
    cout << ans << '\n';

    return 0;
}