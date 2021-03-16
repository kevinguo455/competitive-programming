/*
CCCHK '08 J3 - Phone book
Key Concepts: Implementation (STL maps)
https://dmoj.ca/problem/hkccc08j3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

map<int, string> name;
map<int, int> freq;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    string s; int t;
    while (N--) {
        cin >> s >> t;
        name[t] = s;
    }

    int Q; cin >> Q;
    while (Q--) {
        cin >> t;
        freq[t]++;
    }

    string ans; int max = -1;
    for (pair<int, int> p : freq) {
        if (p.second > max) {
            max = p.second;
            ans = name[p.first];
        }
    }

    cout << ans << '\n';

    return 0;
}