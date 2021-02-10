/*
AtCoder Beginner Contest 191 Problem A - Vanishing Pitch 
Key Concepts: Implementation
https://atcoder.jp/contests/abc191/tasks/abc191_a
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    b *= a;
    c *= a;
    cout << ((b <= d && d <= c) ? "No\n" : "Yes\n");
    return 0;
}