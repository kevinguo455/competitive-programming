/*
CCC '21 J4 - Arranging Books
Key Concepts: Greedy Algorithms
https://dmoj.ca/problem/ccc21j4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

    int lc = 0, mc = 0, sc = 0;
    string str; cin >> str;
    for (char c : str) {
        if (c == 'L') lc++;
        else if (c == 'M') mc++;
        else if (c == 'S') sc++;
    }
    int idx = 0, l = 0, m = 0, s = 0;
    for (; lc; lc--, idx++) if (str[idx] != 'L') l++;
    for (; mc; mc--, idx++) if (str[idx] == 'S') m++;
    for (; sc; sc--, idx++) if (str[idx] == 'M') s++;
    cout << l + max(m, s) << '\n';

    return 0;
}