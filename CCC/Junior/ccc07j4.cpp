/*
CCC '07 J4 - Anagram Checker
Key Concepts: Implementation
https://dmoj.ca/problem/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int freq[26];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string a, b;
    getline(cin, a);
    getline(cin, b);

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == ' ') continue;
        freq[a[i] - 'A']++;
    }

    for (int i = 0; i < b.size(); i++) {
        if (b[i] == ' ') continue;
        freq[b[i] - 'A']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i]) {
            cout << "Is not an anagram.\n";
            return 0;
        }
    }
    cout << "Is an anagram.\n";
    return 0;
}