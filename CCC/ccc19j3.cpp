/*
CCC '19 J3 - Cold Compress
Key Concepts: Implementation
https://dmoj.ca/problem/ccc19j3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int n; cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        char p = s[0];
        int a = 0;
        for (char c : s) {
            if (c == p) {
                a++;
            }
            else {
                cout << a << " " << p << " ";
                a = 1;
            }
            p = c;
        }
        cout << a << " " << p << "\n";
    }

}