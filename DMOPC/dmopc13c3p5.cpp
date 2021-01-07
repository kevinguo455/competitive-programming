/*
DMOPC '13 Contest 3 P5 - A Romantic Dinner
Key Concepts: Dynamic Programming (2D Knapsack)
https://dmoj.ca/problem/dmopc13c3p5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXT = 301, MAXF = 101;

int dp[MAXT][MAXF];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int tmax, fmax, r; cin >> tmax >> fmax >> r;
    int v, t, f;

    for (int cr = 0; cr < r; cr++) {
        cin >> v >> t >> f;

        // dp[i][j] = max value at i units of time and j units of food
        for (int j = fmax; j >= f; j--) {
            for (int i = tmax; i >= t; i--) {
                dp[i][j] = max(dp[i][j], dp[i-t][j-f] + v);
            }
        }
    }

    cout << dp[tmax][fmax] << "\n";

    return 0;
}