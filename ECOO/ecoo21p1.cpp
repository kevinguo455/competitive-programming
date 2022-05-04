/*
ECOO '21 P1 - Many Messages
Key Concepts: Implementation
https://dmoj.ca/problem/ecoo21p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int a, b, c; cin >> a >> b >> c;
    a += b;
    if (a >= c) {
        cout << a << '\n';
        return 0;
    }
    a += b;
    if (a >= c) {
        cout << a << '\n';
        return 0;
    }
    a += b;
    if (a >= c) {
        cout << a << '\n';
        return 0;
    }
    cout << "Who knows...\n";

    return 0;
}
