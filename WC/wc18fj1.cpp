/*
WC '18 Finals J1 - Conditional Contracts
Key Concepts: Implementation
https://dmoj.ca/problem/wc18fj1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    map<int, int> m;
    for (int i = 0, x; i < N; i++) { 
        cin >> x;
        m[x]++;
    }
    int q1 = 0, q2 = 0, t;
    for (auto p : m) {
        if (p.se > q1) {
            q1 = p.se;
            t = p.fi;
        }
    }
    for (auto p : m) {
        if (p.se > q2 && p.fi != t) {
            q2 = p.se;
        }
    }
    cout << q1 + q2 << '\n';

    return 0;
}