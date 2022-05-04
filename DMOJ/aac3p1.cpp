/*
An Animal Contest 3 P1 - Monkey Shopping
Key Concepts: Implementation
https://dmoj.ca/problem/aac3p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int A, B, C, D; cin >> A >> B >> C >> D;
    if (A < B && C < D) cout << "Go to the department store\n";
    else if (A < B) cout << "Go to the grocery store\n";
    else if (C < D) cout << "Go to the pharmacy\n";
    else cout << "Stay home\n";

    return 0;
}