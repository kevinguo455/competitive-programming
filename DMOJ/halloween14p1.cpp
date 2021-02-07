/*
Halloween '14 Contest P1 - Rabbit Girls
Key Concepts: Simple Math
https://dmoj.ca/problem/halloween14p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int n, k; cin >> n >> k;
    if (n <= k) {
        cout << k - n << "\n";
    }
    else {
        cout << min(n%k, k - n%k) << "\n";
    }

    return 0;
}