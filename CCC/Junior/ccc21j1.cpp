/*
CCC '21 J1 - Boiling Water
Key Concepts: Implementation
https://dmoj.ca/problem/ccc21j1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int b; cin >> b;
    int p = 5*b - 400;
    cout << p << '\n' << (b == 100 ? "0" : (b < 100 ? "1" : "-1")) << '\n';
}