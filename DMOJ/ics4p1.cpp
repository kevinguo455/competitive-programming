/*
Word Scrambler
Key Concepts: Brute Force
https://dmoj.ca/problem/ics4p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

set<string> s;
string str;

int main() {
    cin >> str;
    sort(str.begin(), str.end());
    int arr[str.length()];
    iota(arr, arr + str.length(), 0);

    do {
        string t;
        for (int i = 0; i < str.length(); i++) {
            t += str[arr[i]];
        }
        if (s.find(t) == s.end()) {
            s.insert(t);
            cout << t << '\n';
        }
    }
    while (next_permutation(arr, arr + str.length()));

    return 0;
}