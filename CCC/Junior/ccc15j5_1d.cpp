/*
CCC '15 J5 - π-day
Key Concepts: Dynamic Programming
https://dmoj.ca/problem/ccc15j5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 251;

int dp0[MAXN];
int dp1[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int mn, mk; cin >> mn >> mk;
    dp0[0] = 1;

    for (int k = 1; k <= mk; k++) {
        dp1[k-1] = 0;
        for (int n = k; n <= mn; n++) {
            dp1[n] = dp1[n-k] + dp0[n-1];
        }
        for (int n = k; n <= mn; n++) {
            dp0[n] = dp1[n];
        }
    }

    cout << dp1[mn] << "\n";

    return 0;
}