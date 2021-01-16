/*
DMOPC '19 Contest 4 P1 - Valid Strings
Key Concepts: Implementation
https://dmoj.ca/problem/dmopc19c4p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int cases; cin >> cases;
    for (int casen = 0; casen < cases; casen++) {
        
        string s; cin >> s;
        int c = 0;
        for (int i = 0; i < (int) s.length(); i++) {
            if (s[i] == '(') {
                c++;
            }
            else if (s[i] == ')') {
                c--;
                if (c < 0) break;
            }
        }
        cout << (c == 0 ? "YES" : "NO") << "\n";
    }

    return 0;
}