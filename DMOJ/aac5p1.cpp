/*
An Animal Contest 5 P1 - Bamboo Cookies
Key Concepts: Implementation
https://dmoj.ca/problem/aac5p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5; 

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, odd = 0, even = 0;
    cin >> N;
    while (N--) {
        int x; cin >> x;
        if (x % 2 == 1) odd++;
        else even++;
    }
    cout << odd/2 + even/2 << '\n';

    return 0;
}