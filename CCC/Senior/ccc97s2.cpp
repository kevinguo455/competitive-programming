/*
CCC '97 S2 - Nasty Numbers
Key Concepts: Brute Force
https://dmoj.ca/problem/ccc97s2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int cases; cin >> cases;
    while (cases--) {
        int n; cin >> n;
        bool nasty = 0;
        for (int i = 1; i*i <= n; i++) {
            if (n % i == 0) {
                int d = i + n/i;
                for (int j = 1; j+d <= n; j++) {
                    if (j == i || j == n/i) continue;
                    if (j * (j+d) == n) {
                        nasty = 1;
                        break;
                    }
                }
            }
            if (nasty) break;
        }
        cout << n << " is " << (nasty ? "" : "not ") << "nasty\n";
    }

    return 0;
}