/*
BlueBook - Change
Key Concepts: Implementation
https://dmoj.ca/problem/p109ex10
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int m, t, q = 0, d = 0, n = 0, c = 0;
    cin >> m;
    t = m;
    while (m >= 25) {
        q++;
        m -= 25;
    }
    while (m >= 10) {
        d++;
        m -= 10;
    }
    while (m >= 5) {
        n++;
        m -= 5;
    }
    while (m >= 1) {
        c++;
        m -= 1;
    }
    cout << t << " cent";
    if (t > 1) cout << "s";
    cout << " requires";
    bool comma = 0;
    if (q != 0) {
        if (comma) cout << ",";
        cout << " " << q << " quarter";
        if (q > 1) cout << "s";
        comma = 1;
    }
    if (d != 0) {
        if (comma) cout << ",";
        cout << " " << d << " dime";
        if (d > 1) cout << "s";
        comma = 1;
    }
    if (n != 0) {
        if (comma) cout << ",";
        cout << " " << n << " nickel";
        if (n > 1) cout << "s";
        comma = 1;
    }
    if (c != 0) {
        if (comma) cout << ",";
        cout << " " << c << " cent";
        if (c > 1) cout << "s";
        comma = 1;
    }
    cout << "." << endl;
    return 0;
}