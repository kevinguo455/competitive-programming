/*
CCC '20 J2 - Epidemiology
Key Concepts: Simulation
https://dmoj.ca/problem/ccc20j2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int p, n, r; cin >> p >> n >> r;
    int a = n, d = 0;
    while (a <= p) {
        n *= r;
        a += n;
        d++;
    }
    cout << d << "\n";

    return 0;
}