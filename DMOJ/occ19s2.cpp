/*
OCC '19 S2 - Rimuru's Number Game
Key Concepts: Brute Force, Recursion
https://dmoj.ca/problem/occ19s2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll M;

int solve(ll n) {
    if (n > M) return 0;
    n *= 10;
    return solve(n+2) + solve(n+3) + 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> M;
    cout << solve(2) + solve(3) << '\n';

    return 0;
}