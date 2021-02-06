/*
Avocado Trees!
Key Concepts: Data Structures (Prefix Sum Array)
https://dmoj.ca/problem/avocadotrees
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5; 

int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q, H; cin >> N >> Q >> H;
    int a, b;
    
    // init prefix sum array
    for (int i = 1; i <= N; i++) {
        cin >> a >> b;
        if (a <= H) arr[i] += b;
        arr[i+1] += arr[i];
    }

    // find max range sum
    int ans = 0;
    while (Q--) {
        cin >> a >> b;
        ans = max(ans, arr[b] - arr[a-1]);
    }
    cout << ans << "\n";

    return 0;
}