/*
CCC '20 J1 - Dog Treats
Key Concepts: Implementation
https://dmoj.ca/problem/ccc20j1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int a, b, c; cin >> a >> b >> c;
    cout << (a + 2*b + 3*c < 10 ? "sad" : "happy") << endl;

    return 0;
}