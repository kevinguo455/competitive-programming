/*
CCC '20 J4 - Cyclic Shifts
Key Concepts: Brute Force
https://dmoj.ca/problem/ccc20j4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string t, s, b; cin >> t >> s;
    int n = s.length();
    s += s;
    // try search every cyclic shift
    for (int i = 0; i < n; i++) {
        b = s.substr(i, n);
        if (t.find(b) != string::npos) {
            cout << "yes\n";
            return 0;
        }
    }

    cout << "no\n";
    return 0;
}