/*
COCI '07 Contest 4 #4 Muzicari
Key Concepts: Dynamic Programming (balancing act)
https://dmoj.ca/problem/coci07c4p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXT = 5001, MAXN = 501;

int arr[MAXN];          // length of break for each musician
vector<int> dp[MAXT];   // a working arrangement of breaks for a concert length T
bitset<MAXT> vis;       // has this state been reached yet?
bitset<MAXN> selected;  // has this musician been assigned yet?
int ans[MAXN];          // the location of the nth musician's break

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T, N; cin >> T >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    // reduce problem to partitioning the lengths of the breaks into two groups that have sum <= T

    vis[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = T-arr[i]; j >= 0; j--) {
            if (vis[j] && !vis[j+arr[i]]) {
                // copy over solution
                for (int k : dp[j]) dp[j+arr[i]].push_back(k);
                // extend solution
                dp[j+arr[i]].push_back(i);
                vis[j+arr[i]] = 1;
            }
        }
    }

    // reconstruct solution
    int idx = 0;
    for (int i = T; i >= 0; i--) {  // first row
        if (vis[i]) {
            for (int j : dp[i]) {
                ans[j] = idx;
                idx += arr[j];
                selected[j] = 1;
            }
            break;
        }
    }
    idx = 0;
    for (int i = 0; i < N; i++) {   // second row
        if (!selected[i]) {
            ans[i] = idx;
            idx += arr[i];
        }
    }

    // output solution
    for (int i = 0; i < N; i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}