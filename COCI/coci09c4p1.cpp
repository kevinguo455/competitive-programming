/*
Solution to COCI '09 Contest 4 Problem 1 - Autori
Key Concepts: Implementation
Solution by Kevin Guo
https://dmoj.ca/problem/coci09c4p1
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    string s; cin >> s;
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') cout << c;
    }

    return 0;
}