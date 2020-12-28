/*
WC '18 Contest 1 J2 - Making the Cut
Key Concepts: Implementation
https://dmoj.ca/problem/wc18c1j2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string x, y; cin >> x;
    for (int i = 0 ; i < 5; i++) {
        cin >> y;
        if (x == y) {
            cout << "Y\n";
            return 0;
        }
    }
    cout << "N\n";
    return 0;
}