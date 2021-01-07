/*
Codeforces Round #690 (Div. 3) - B. Last Year's Substring
Key Concepts: Brute Force, Implementation
https://codeforces.com/contest/1462/problem/B
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int cases; cin >> cases;
    string cmp = "2020";
    for (int casen = 0; casen < cases; casen++) {
        int n; cin >> n;
        string s; cin >> s;

        int l = 0;
        for (int i = 0; i < min(s.length(), cmp.length()); i++) {
            if (s[i] == cmp[i]) l++;
            else break;
        }
        for (int i = 1; i <= min(s.length(), cmp.length()); i++) {
            if (l == cmp.length()) break;
            if (s[s.length() - i] == cmp[cmp.length() - i]) {
                l++;
            }
            else break;
        }

        if (l == cmp.length()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}