/*
An Animal Contest 1 P3 - Happy Alpacas
Key Concepts: Simple Math (parity)
https://dmoj.ca/problem/aac1p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, X; cin >> N >> X; X = N - X;
    
    if (X % 2 == 1) {
        cout << "-1\n";
        return 0;
    }

    if (X == N) {
        cout << "1 0";
        X -= 2, N -= 2;
    }
    else {
        cout << '0'; 
        N--;
    }

    while (X-- && X-- && N-- && N--) cout << " 1 0";
    while (N--) cout << " 0";
    cout << '\n';

    return 0;
}