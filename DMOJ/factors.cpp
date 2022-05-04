/*
Factors
Key Concepts: Factorization
https://dmoj.ca/problem/factors
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, int> factorize(ll n) {
    map<ll, int> res;
    while (n > 1) {
        int i = 2;
        int lim = floor(sqrt(n));
        while (n % i != 0 && i <= lim) i++;
        if (i > lim) {
            res[n]++;
            break;
        }
        res[i]++;
        n /= i;
    }
    return res;
}

map<ll, int> merge_factors(map<ll, int> a, map<ll, int> b) {
    for (pair<ll, int> p : b) {
        a[p.first] += p.second;
    }
    return a;
}

ll factors(map<ll, int> f) {
    ll res = 1;
    for (pair<ll, int> p : f) {
        res *= p.second+1;
    }
    return res;
}

int main() {
    ll A, B; cin >> A >> B;

    map<ll, int> m = factorize(B-A+1);
    map<ll, int> n = factorize(A+B);
    map<ll, int> f = merge_factors(m, n);
    f[2]--;

    cout << factors(f) << '\n';
}