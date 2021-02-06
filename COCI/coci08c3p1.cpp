/*
COCI '08 Contest 3 #1 Pet
Key Concepts: Implementation
https://dmoj.ca/problem/coci08c3p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<pair<int, int>> v;
    for (int i = 1; i <= 5; i++) {
        v.push_back({0, i});
        for (int j = 0; j < 4; j++) {
            int x; cin >> x;
            v[i-1].first += x;
        }
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    cout << v[0].second << " " << v[0].first << "\n";

    return 0;
}