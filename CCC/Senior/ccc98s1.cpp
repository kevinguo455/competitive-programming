/*
CCC '98 S1 - Censor
Key Concepts: Implementation
https://dmoj.ca/problem/ccc98s1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    cin.ignore();
    while (n--) {
        string s; getline(cin, s);
        stringstream ss(s);
        string w;
        while (ss >> w) {
            if (w.length() == 4) cout << "**** ";
            else cout << w << " ";
        }
        cout << "\n";
    }

    return 0;
}