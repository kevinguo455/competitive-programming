/*
DMOPC '19 Contest 6 P0 - Trivial Math
Key Concepts: Implementation, Simple Math (triangle inequality)
https://dmoj.ca/problem/dmopc19c6p0
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    cout << (v[0] + v[1] > v[2] ? "yes" : "no") << "\n";

    return 0;
}