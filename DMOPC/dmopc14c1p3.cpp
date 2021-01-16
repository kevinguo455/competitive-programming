/*
DMOPC '14 Contest 1 P3 - New Students
Key Concepts: Implementation
https://dmoj.ca/problem/dmopc14c1p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    int s = 0;
    int x; 
    for (int i = 0; i < n; i++) { 
        cin >> x;
        s += x;
    }
    int q; cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> x;
        s += x;
        cout << s / (double) (i+n) << "\n";
    }

    return 0;
}