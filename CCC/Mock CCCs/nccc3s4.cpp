/*
Mock CCC '18 Contest 3 S4 - A Graph Problem
Key Concepts: Greedy Algorithms
https://dmoj.ca/problem/nccc3s4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, m = 0; cin >> N;
    long long tot = 0;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        tot += x;
        m = max(m, x);
    }
    cout << (tot % 2 == 0 && m <= tot/2 ? "YES" : "NO") << '\n';

    return 0;
}