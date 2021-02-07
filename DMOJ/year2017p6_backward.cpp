/*
New Year's 2017 Problem 6 - Christmas Cards
Key Concepts: Dynamic Programming (knapsack)
https://dmoj.ca/problem/year2017p6
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ms(x,a) memset(x,a,sizeof(x))
#define fio cin.tie(0)->sync_with_stdio(0)
const int MAXN = 5001;

ll dp[MAXN];    // stores min cost to draw to this card

int main() {
    fio;

    ms(dp, 0x3f);            
    dp[0] = 0;
    int n, cost, draw; cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> cost >> draw;
        for (int j = n-1; j >= i; j--) {
            dp[min(n-1,j+draw)] = min(dp[min(n-1,j+draw)], dp[j] + cost);
        }
    }
    
    cout << dp[n-1] << "\n";

    return 0;
}