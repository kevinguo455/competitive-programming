/*
Mock CCC '21 S1 - Edit Distance
Key Concepts: Implementation
https://dmoj.ca/problem/nccc8s1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string a, b; cin >> a >> b;
    int n = b.length();

    set<string> strings;

    // add
    for (int i = 0; i <= n; i++) {
        for (char c : a) {
            string s = b.substr(0, i) + c + b.substr(i, n);
            if (s != b) strings.insert(s);
        }
    }

    // change
    for (int i = 0; i < n; i++) {
        for (char c : a) {
            string s = b.substr(0, i) + c + b.substr(i+1, n);
            if (s != b) strings.insert(s);
        }
    }

    // remove
    for (int i = 0; i < n; i++) {
        string s = b.substr(0, i) + b.substr(i+1, n);
        if (s != b) strings.insert(s);
    }

    for (string s : strings) {
        cout << s << '\n';
    }

    return 0;
}