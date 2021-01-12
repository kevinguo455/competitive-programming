/*
Wesley's Anger Contest 4 Problem 2 - Squirrel Election
Key Concepts: Dynamic Programming (0-1 knapsack)
https://dmoj.ca/problem/wac4p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
typedef long long ll;
const int MAXN = (5000 >> 1) + 2; 

ll dp[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    int w, v, vt = 0;    // w = weight, v = value
    queue<int> wq, vq;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        wq.push((w>>1)+1);
        vq.push(v);
        vt += v;
    }
    vt >>= 1;
    vt += 1;

    // knapsack
    ms(dp, 0x3f);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        w = wq.front();
        v = vq.front();
        wq.pop();
        vq.pop();
        for (int j = vt; j > v; j--) {
            dp[j] = min(dp[j], dp[j-v] + w);
        }
        for (int j = v; j >= 0; j--) {
            dp[j] = min(dp[j], (ll)w);
        }
    }

    cout << dp[vt] << "\n";

    return 0;
}