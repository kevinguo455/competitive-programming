/*
COCI '18 Contest 3 #1 Magnus
Key Concepts: Implementation
https://dmoj.ca/problem/coci18c3p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string s; cin >> s;
    int l = -1, c = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
        if (l == -1 && s[i] == 'H') l++;
        else if (l == 0 && s[i] == 'O') l++;
        else if (l == 1 && s[i] == 'N') l++;
        else if (l == 2 && s[i] == 'I') {
            c++;
            l = -1;
        }
    }
    cout << c << endl;
    return 0;
}