/*
GFSSOC '17 S2 - Ace is Base
Key Concepts: Simple Math, Implementation
https://dmoj.ca/problem/gfssoc16s2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> v;

void build(string s) {
    if (s.length() != 0) v.push_back(stoll(s, nullptr, 16));
    if (s.length() == 9) return;
    build('a' + s);
    build('c' + s);
    build('e' + s);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    build("");
    sort(v.begin(), v.end());

    ll a, b; cin >> a >> b;
    cout << upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a) << '\n';

    return 0;
}