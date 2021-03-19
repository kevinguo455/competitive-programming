/*
Unexpected Factorial
Key Concepts: Implementation
https://dmoj.ca/problem/hci16ufactorial
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s; getline(cin, s);

    int fac = 0;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '!') {                      // factorial detected
            if ('0' <= s[i-1] && s[i-1] <= '9') {
                fac += s[i-1] - '0';            // get first digit
                if (i != 1 && '0' <= s[i-2] && s[i-2] <= '9') {
                    fac += (s[i-2] - '0') * 10; // get second digit
                }
                break;
            }
        }
        if (i+1 == s.length()) {
            cout << "-1\n";
            return 0;
        }
    }

    ll ans = 1;
    for (int i = 2; i <= fac; i++) ans *= i;
    cout << ans << '\n';

    return 0;
}