/*
An Animal Contest 1 P1 - Alpaca Shapes
Key Concepts: Implementation
https://dmoj.ca/problem/aac1p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll S, R; cin >> S >> R;
    cout << (S*S*100 > R*R*314 ? "SQUARE" : "CIRCLE") << '\n';

    return 0;
}