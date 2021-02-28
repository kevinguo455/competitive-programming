/*
CCC '10 S2 - Huffman Encoding
Key Concepts: Implementation
https://dmoj.ca/problem/ccc10s2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    map<string, char> m;
    char c; string s;
    while (N--) {
        cin >> c >> s;
        m[s] = c;
    }
    cin >> s;
    string l = "";
    for (int i = 0; i < s.length(); i++) {
        l += s[i];
        if (m[l]) {
            cout << m[l];
            l = "";
        }
    }
    cout << '\n';


    return 0;
}