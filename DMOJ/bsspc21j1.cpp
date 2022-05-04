/*
BSSPC '21 J1 - Eggy's New Clothes
Key Concepts: Implementation
https://dmoj.ca/problem/bss21j1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int S, X; cin >> S >> X;
    cout << (X >= (S+2)*3+16 ? "Yes it fits!" : "No, it's too small :(") << '\n';

    return 0;
}