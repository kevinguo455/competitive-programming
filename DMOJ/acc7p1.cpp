/*
Another Contest 7 Problem 1 - Lonely Users
Key Concepts: Implementation 
https://dmoj.ca/problem/acc7p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T;
    while (T--) {
        int x; cin >> x; 
        if (x == 2) cout << 2 << '\n';
        else cout << x-1 << '\n';
    }

    return 0;
}