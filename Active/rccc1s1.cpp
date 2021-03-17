/*
Riolku's Mock CCC S1 - Word Bot
Key Concepts: Implementation
https://dmoj.ca/problem/rccc1s1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, C, V; cin >> N >> C >> V;
    string s; cin >> s;
    for (int i = 0, c = 0, v = 0; i < N; i++) {
        if (s[i] == 'y') {
            c++;
            v++;
        }
        else if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            c = 0;
            v++;
        }
        else {
            v = 0;
            c++;
        }
        if (c > C || v > V) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}