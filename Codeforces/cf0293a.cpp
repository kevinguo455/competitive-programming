/*
Codeforces Round #293 (Div. 2) - A. Vitaly and Strings
https://codeforces.com/problemset/problem/518/A
Key Concepts: Implementation
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    string a, b;
    cin >> a >> b;

    int i = a.length() - 1;
    while (true) {
        a[i]++;
        if (a[i] > 'z') {
            a[i] = 'a';
            i--;
            if (i < 0) {
                a = 'a' + a;
                break;
            }
        }
        else break;
    }

    if (a == b) cout << "No such string\n";
    else cout << a << "\n";

    return 0;
}