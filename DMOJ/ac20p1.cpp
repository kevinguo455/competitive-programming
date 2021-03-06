/*
Appleby Contest '20 P1 - Terrific Triangles
Key Concepts: Implementation
https://dmoj.ca/problem/ac20p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char triangle(ll a, ll b, ll c) {
    if (a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b) return 'R';
    if (a*a + b*b < c*c || b*b + c*c < a*a || a*a + c*c < b*b) return 'O';
    return 'A';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int cases; cin >> cases;
    while (cases--) {
        ll a, b, c; cin >> a >> b >> c;
        cout << triangle(a, b, c) << '\n';
    }

    return 0;
}