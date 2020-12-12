/*
DWITE '07 R2 #1 - Not Quite Prime
Key Concepts: Simple Math, Brute Force
https://dmoj.ca/problem/dwite07c2p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

bool semiprime(int n) {
    short c = 0;
    for (int i = 2; c < 2 && i*i <= n; i++) {
        while (n % i == 0) {
            n/=i;
            c++;
        }
    }
    if (n > 1) {
        c++;
    }
    return c == 2;
}

int main() {
    for (int i = 0; i < 5; i++) {
        int n; cin >> n;
        cout << (semiprime(n) ? "semiprime" : "not") << endl;
    }
    return 0; 
}