/*
An Animal Contest 3 P2 - Monkey Potato
Key Concepts: Implementation
https://dmoj.ca/problem/aac3p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int K, D; cin >> K >> D;

    bool zero = false;
    int min_digit = 11;
    for (int i = 0, x; i < D; i++) {
        cin >> x;
        if (x) min_digit = min(min_digit, x);
        else zero = 1;
    }

    if (min_digit == 11) cout << "-1\n";
    else {
        if (K <= 2) {
            while (K--) cout << min_digit;
            cout << '\n';
        }
        else {
            cout << min_digit; K -= 2;
            if (zero) while (K--) cout << '0';
            else while (K--) cout << min_digit;
            cout << min_digit << '\n';
        }
    }

    return 0;
}