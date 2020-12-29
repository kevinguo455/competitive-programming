/*
COCI '08 Contest 1 #1 Skocimis
Key Concepts: Simple Math
https://dmoj.ca/problem/coci08c1p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    cout << max(b-a, c-b) - 1 << "\n";
}