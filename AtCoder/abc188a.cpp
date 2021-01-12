/*
AtCoder Beginner Contest 188 Problem A - Three-Point Shot 
Key Concepts: Implementation
https://atcoder.jp/contests/abc188/tasks/abc188_a
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int x, y; cin >> x >> y;
    cout << (abs(x-y) < 3 ? "Yes" : "No") << endl; 

    return 0;
}