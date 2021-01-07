/*
AtCoder Beginner Contest 187 Problem C - 1-SAT  
Key Concepts: Data Structures (hashset), Implementation
https://atcoder.jp/contests/abc187/tasks/abc187_c
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    unordered_set<string> s;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        s.insert(str);
    }
    for (string x : s) {
        if (s.find("!" + x) != s.end()) {
            cout << x << "\n";
            return 0;
        }
    }
    cout << "satisfiable\n";
    return 0;
}