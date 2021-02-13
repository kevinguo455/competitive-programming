/*
Mock CCC '18 Contest 2 J3/S1 - An Array Problem
Key Concepts: Simulation
https://dmoj.ca/problem/nccc2j3s1
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m = 0, x; cin >> n;
    long long tot = 0;
    while (n--) {
        cin >> x;
        m = max(m, x);
        tot += x;
    }
    cout << min(tot/2, tot-m) << '\n';

    return 0;
}