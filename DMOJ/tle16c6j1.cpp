/*
TLE '16 Contest 6 (Mock CCC) J1 - Paper Printing
Key Concepts: Implementation
https://dmoj.ca/problem/tle16c6j1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int n, m, a; cin >> n >> m >> a;
    int x = 0, q;
    for (int i = 0; i < a; i++) {
        n += x;
        cin >> x >> q;
        n -= x;
        n += q;
        if (n < q) {
            cout << "The printer melts at " << x+n-q+1 << " second(s)." << endl;
            return 0;
        }
        if (n > m) {
            cout << "The printer jams at " << x << " second(s)." << endl;
            return 0;
        }
    }
    cout << "The printer melts at " << x+n+1 << " second(s)." << endl;

    return 0;
}