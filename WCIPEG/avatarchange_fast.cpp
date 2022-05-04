/*
PEG Test '14 - Change
Key Concepts: Recursion
https://dmoj.ca/problem/avatarchange
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int ans;

int a[6];
int b[4];
int c[6];
int d[4];

int check() {
    memset(d, 0, sizeof d);
    for (int i = 0; i < 6; i++) {
        d[c[i]] += a[i];
    }
    int out = 0;
    for (int i = 0; i < 4; i++) {
        if (d[i] > b[i]) out++;
    }
    return out;
}

void eval(int idx) {
    if (idx == 6) {
        ans = max(ans, check());
        return;
    }
    for (int i = 0; i < 4; i++) {
        c[idx] = i;
        eval(idx+1);
    }
}


int main() {

    cin >> b[0] >> b[1] >> b[2] >> b[3];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];

    eval(0);

    cout << ans << '\n';

    return 0;
}