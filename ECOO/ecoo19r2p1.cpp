/*
ECOO '19 R2 P1 - Email
Key Concepts: Implementation
https://dmoj.ca/problem/ecoo19r2p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int CASES = 10; 
    while (CASES--) {
        int N; cin >> N;
        set<string> emails;
        while (N--) {
            string s, t = ""; cin >> s;
            bool at = 0, plus = 0;
            for (char c : s) {
                if (c == '@') at = 1, t += c;
                if (at) t += tolower(c);
                else if (c == '+') plus = 1;
                else if (!plus && c != '.') t += tolower(c);
            }
            emails.insert(t);
        }
        cout << emails.size() << '\n';
    }

    return 0;
}