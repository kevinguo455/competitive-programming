/*
Mock CCC '18 Contest 1 J2 - A Substring Problem
Key Concepts: Implementation
https://dmoj.ca/problem/nccc1j2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1]) {
            cout << "Even\n";
            return 0;
        }
    }
    
    cout << "Odd\n";
    return 0;
}