/*
COCI '08 Contest 5 #1 Ljesnjak
Key Concepts: Implementation
https://dmoj.ca/problem/coci08c5p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;
    int ans = 0;
    for (int i = 1; i < (int) s.length(); i++) {
        if (s[i] == 'j' && (s[i-1] == 'l' || s[i-1] == 'n')) ans++;
        else if (s[i] == '=' || s[i] == '-') ans++;
        if (i >= 2 && s[i] == '=' && s[i-1] == 'z' && s[i-2] == 'd') ans++;
    }
    cout << s.length() - ans << '\n';

    return 0;
}