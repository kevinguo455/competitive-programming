/*
PEG Test - Halloween 2014 - Brap Lesh Mafia
Key Concepts: Implementation, Simple Math
https://dmoj.ca/problem/brapleshmafia
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K; cin >> N >> K;
    ll ans = 0, a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        ans += a * b % K;
    }
    cout << ans % K << '\n';

    return 0;
}