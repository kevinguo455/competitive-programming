/*
A Sum Problem
Key Concepts: Binary Search, Recursion
https://dmoj.ca/problem/asumproblem
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sum(ll l, ll r, ll clr, ll cr) {
    if (l == r) return clr * l;
    if (clr == 0 || l > r) return 0;

    ll m = (l+r)/2;
    ll cmr;
    printf("? %lld\n", m+1);
    scanf("%lld", &cmr);
    
    return sum(l, m, clr+cr-cmr, cmr) + sum(m+1, r, cmr-cr, cr);
}

int main() {

    ll n; scanf("%lld", &n);
    printf("! %lld\n", sum(0, 1e7+5, n, 0));

    return 0;
}