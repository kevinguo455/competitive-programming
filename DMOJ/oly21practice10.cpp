/*
Bob's Restaurant
Key Concepts: Implementation
https://dmoj.ca/problem/oly21practice10
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6+5; 

int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K; cin >> N >> K;
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        arr[b] += a;
    }

    int idx = 0, c = 0;
    for (; idx <= min(K*2, MAXN-1); idx++) {
        c += arr[idx];
    }
    int ans = c;
    for (int i = idx; i < MAXN; i++) {
        c += arr[i];
        c -= arr[i-idx];
        ans = max(ans, c);
    }
    cout << ans << '\n';

    return 0;
}