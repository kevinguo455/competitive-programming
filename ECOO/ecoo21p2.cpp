/*
ECOO '21 P2 - DNA Derren
Key Concepts: Implementation
https://dmoj.ca/problem/ecoo21p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;
    cout << s[0];
    for (int i = 1; i < s.length(); i++) {
        if (!((s[i-1] == 'A') ^ (s[i] == 'A'))) cout << ' ';
        cout << s[i];
    }
    cout << '\n';

    return 0;
}
