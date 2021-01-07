/*
AtCoder Beginner Contest 187 Problem A - Large Digits 
Key Concepts: Implementation
https://atcoder.jp/contests/abc187/tasks/abc187_a
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int s(string n) {
    int out = 0;
    for (char c:n) out += c - '0';
    return out;
}

int main() {
    string a, b; cin >> a >> b;
    cout << max(s(a), s(b));
    return 0;
}