/*
VM7WC '16 #4 Silver - Tests or Test Cases?
Key Concepts: Recursion
https://dmoj.ca/problem/vmss7wc16c4p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26; 

int N, L;
vector<char> rules[MAXN];
set<string> ans;

void solve(string s, int idx) {
    if (s.length() == L || idx > N) {
        ans.insert(s);
        return;
    }
    solve(s, idx+1);
    if (idx != N) for (char c : rules[idx]) solve(s+c, idx+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> L;

    char c;
    for (int i = 0, t; i < N; i++) {
        cin >> t;
        while (t--) {
            cin >> c;
            rules[i].push_back(c);
        }
    }

    for (char c : rules[0]) solve({c}, 1);

    for (string s : ans) cout << s << '\n';

    return 0;
}