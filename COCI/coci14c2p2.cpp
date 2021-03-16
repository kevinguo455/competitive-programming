/*
COCI '14 Contest 2 #2 Utrka
Key Concepts: Implementation
https://dmoj.ca/problem/coci14c2p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

unordered_multiset<string> s;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        s.insert(str);
    }

    for (int i = 1; i < N; i++) {
        cin >> str;
        s.erase(s.find(str));
    }

    cout << *s.begin() << '\n';

    return 0;
}