/*
Mackenzie New Year's Challenge '17 - Problem 2: ASCII Art II
Key Concepts: Implementation
https://dmoj.ca/problem/mnyc17p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin >> N >> N;
    set<char> colours;
    int ans = 0;
    cin.ignore();

    while (N--) {
        string s;
        getline(cin, s);
        for (char c : s) {
            if (c == ' ') continue;
            if (c != '.') colours.insert(c);
            ans++;
        }
    }

    cout << ans + colours.size() << '\n'; 

    return 0;
}