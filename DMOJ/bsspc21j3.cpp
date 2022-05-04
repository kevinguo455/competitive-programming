/*
BSSPC '21 J3 - Magic Paint Gun Cartridges
Key Concepts: Implementation
https://dmoj.ca/problem/bsspc21j3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

inline bool r(char c) {
    return (c == 'R' || c == 'O' || c == 'P' || c == 'B');
}

inline bool y(char c) {
    return (c == 'Y' || c == 'O' || c == 'G' || c == 'B');
}

inline bool b(char c) {
    return (c == 'U' || c == 'G' || c == 'P' || c == 'B');
}

void scan(string s, function<bool(char)> comp, int &res) {
    bool f = 0;
    for (char c : s) {
        if (comp(c)) {
            if (!f) res++;
            f = 1;
        }
        else f = 0;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int M, N; cin >> M >> N;
    int R = 0, Y = 0, B = 0;

    while (N--) {
        string s; cin >> s;
        scan(s, r, R);
        scan(s, y, Y);
        scan(s, b, B);
    }

    cout << R << ' ' << Y << ' ' << B << '\n';

    return 0;
}