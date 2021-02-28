/*
Mock CCC '20 Contest 2 S2 - 4D BBST on a DP
Key Concepts: Implementation
https://dmoj.ca/problem/mccc2s2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    string s; cin >> s;
    string out = "";
    out += s[0];
    for (int i = 1; i < s.length(); i++) {
        if (s[i] <= out[0]) out = s[i] + out;
        else out = out + s[i];
    }
    cout << out << '\n';

    return 0;
}