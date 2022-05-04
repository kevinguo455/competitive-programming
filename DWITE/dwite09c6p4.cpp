/*
DWITE '09 R6 #4 - Time for Change
Key Concepts: Dynamic Programming (Coins)
https://dmoj.ca/problem/dwite09c6p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXM = 105, MAXN = 15; 

int CASES = 5;
int M, N;
int dp[MAXM], vals[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (CASES--) {
        
        cin >> M >> N;
        memset(dp, 0x3f, sizeof dp);
        memset(vals, 0, sizeof vals);
        for (int i = 0; i < N; i++) cin >> vals[i];
        dp[0] = 0;

        for (int c = 0; c < M; c++) {
            for (int t = 0; t < N; t++) {
                #define v vals[t]
                if (c+v < MAXM) dp[c+v] = min(dp[c+v], dp[c]+1);
            }
        }

        cout << dp[M] << '\n';
    }

    return 0;
}