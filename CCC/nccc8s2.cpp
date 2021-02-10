/*
Mock CCC '21 S2 - Colorful Strings
Key Concepts: Simple Math (combinatorics)
https://dmoj.ca/problem/nccc8s2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int freq[26];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;
    for (char c : s) {
        freq[c-'a']++;
    }

    long long ans = 1;
    for (int i = 0; i < 26; i++) {
        ans = (ans * (freq[i]+1)) % MOD;
    }

    cout << ans << '\n';

    return 0;
}