/*
Bruce's Homework
Key Concepts: Dynamic Programming (0-1 Knapsack)
https://dmoj.ca/problem/olyhwk
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101, MAXW = 8641; 

int N, S, MW;
float v[MAXN];
int w[MAXN];
float dp[MAXW];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> S >> MW;
    
    // init item weights
    for (int i = 1; i <= N; i++) {
        cin >> w[i];
    }

    // init item values
    int p, x;
    int e = 0;
    for (int i = 0; i < S; i++) {
        cin >> p;
        if (p == 0) e++;
        for (int j = 0; j < p; j++) {
            cin >> x;
            v[x] += 1.0/p;
        }
    }

    // knapsack
    for (int j = 1; j <= N; j++) {
        for (int i = MW; i >= w[j]; i--) {
            dp[i] = max(dp[i], dp[i-w[j]] + v[j]);
        }
    }

    //printf("%.2f\n", dp[MW] + e);
    cout << dp[MW] + e << "\n";

    return 0;
}