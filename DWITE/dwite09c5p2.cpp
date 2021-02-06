/*
DWITE '09 R5 #2 - Round to Second Prime
Key Concepts: Implementation
https://dmoj.ca/problem/dwite09c5p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int cases = 0; cases < 5; cases++) {
        int n; cin >> n;
        bool first = 0;
        int up, down;
        for (int i = n+1;;i++) {
            if (isPrime(i)) {
                if (first) {
                    up = i;
                    break;
                }
                else first = 1;
            }
        }
        first = 0;
        for (int i = n-1;;i--) {
            if (isPrime(i)) {
                if (first) {
                    down = i;
                    break;
                }
                else first = 1;
            }
        }
        if (abs(n-down) >= abs(n-up)) {
            cout << up << "\n";
        }
        else {
            cout << down << "\n";
        }
    }

    return 0;
}