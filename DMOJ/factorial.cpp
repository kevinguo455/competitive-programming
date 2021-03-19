/*
Fast Factorial Calculator
Key Concepts: Intermediate Math (modulo)
https://dmoj.ca/problem/factorial
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;
typedef unsigned long long ull;

const ui MAXN = 35; 
ui fac[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // No need to mod, unsigned int overflow automatically mods by 2^32
    fac[0] = 1;
    for (ui i = 1; i < MAXN; i++) {
        fac[i] = fac[i-1] * i;
    }

    ull N, x; cin >> N;
    while (N--) {
        cin >> x;
        if (x >= MAXN) cout << 0 << '\n';
        else cout << fac[x] << '\n';
    }

    return 0;
}