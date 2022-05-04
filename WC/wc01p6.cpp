/*
WC '01 P6 - Mission Impossible 3
Key Concepts: Simple Math (Principle of Inclusion/Exclusion)
https://dmoj.ca/problem/wc01p6
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll T; cin >> T;
    for (ll i = 0, R, a, b; i < T; i++) {
        cin >> R >> a >> b;
        cout << R/a + R/b - R/lcm(a, b) << '\n'; 
    }

    return 0;
}