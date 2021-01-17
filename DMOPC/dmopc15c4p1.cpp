/*
DMOPC '15 Contest 4 P1 - Dictionary
Key Concepts: Implementation
https://dmoj.ca/problem/dmopc15c4p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> v[26];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v[s[0]-'a'].push_back(s);
    }

    for (int i = 0; i < 26; i++) {
        if (v[i].size() == 0) continue;

        sort(v[i].begin(), v[i].end());
        
        cout << v[i][0];
        for (int j = 1; j < (int) v[i].size(); j++) {
            cout << ", " << v[i][j];
        }
        cout << "\n";
    }

    return 0;
}