/*
DMOPC '15 Contest 7 P2 - Not a Wall of Text
Key Concepts: Implementation
https://dmoj.ca/problem/dmopc15c7p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s, t; 
    getline(cin, s);
    stringstream ss(s);
    int ans = 0;
    while (ss >> t) {
        ans++;
    }
    cout << ans << "\n";

    return 0;
}