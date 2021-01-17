/*
DMOPC '14 Contest 6 P1 - Core Drill
Key Concepts: Implementation
https://dmoj.ca/problem/dmopc14c5p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const double PI = 3.14159265359;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int r, h; cin >> r >> h;
    cout << r * r * h * PI / 3 << "\n";

    return 0;
}