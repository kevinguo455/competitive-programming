/*
CCC '06 S4 - Groups
Key Concepts: Brute Force
https://dmoj.ca/problem/ccc06s4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    while (n != 0) {
        int m[n+1][n+1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> m[i][j];
            }
        }

        // identity
        int id = 0;
        for (int i = 1; i <= n; i++) {
            bool identity = 1;
            for (int j = 1; j <= n && identity; j++) {
                if (m[j][i] != j) identity = 0;
            }
            if (identity) {
                id = i;
                break;
            }
        }
        if (id == 0) {
            cout << "no\n";
            cin >> n;
            continue;
        }

        // inverse
        bool inverse = 0;
        for (int i = 1; i <= n; i++) {
            inverse = 0;
            for (int j = 1; j <= n; j++) {
                if (m[i][j] == id) {
                    inverse = 1;
                    break;
                }
            }
            if (!inverse) {
                cout << "no\n";
                cin >> n;
                break;
            }
        }
        if (!inverse) continue;

        // associativity
        bool associative = 1; 
        for (int i = 1; i <= n && associative; i++) {
            for (int j = 1; j <= n && associative; j++) {
                for (int k = 1; k <= n && associative; k++) {
                    if (m[m[i][j]][k] != m[i][m[j][k]]) {
                        cout << "no\n";
                        cin >> n;
                        associative = 0;
                    }
                }
            }
        }
        if (!associative) continue;

        cout << "yes\n";
        cin >> n;
    }

    return 0;
}