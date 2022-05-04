/*
PEG Test '14 - Change
Key Concepts: Brute Force
https://dmoj.ca/problem/avatarchange
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 7;

int ans = 0;

int a[6];
int b[4];
int c[4];

int check() {
    int out = 0;
    for (int i = 0; i < 4; i++) {
        if (c[i] > b[i]) out++;
    }
    return out;
}

void eval(vector<int> v) {
    memset(c, 0, sizeof c);

    int part = 0;
    for (int idx = 0; idx < MAXN; idx++) {
        if (idx >= v[part]) {
            part++;
            if (part >= 4) break;
        }
        c[part] += a[idx];
    }

    ans = max(ans, check());
}

void partition(vector<int> v, int idx) {
    if (idx == v.size()) {
        eval(v);
        return;
    }
    for (v[idx]; v[idx] < MAXN; v[idx]++) {
        if (idx+1 != v.size()) v[idx+1] = v[idx];
        partition(v, idx+1);
    }
}

int main() {

    cin >> b[0] >> b[1] >> b[2] >> b[3];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];

    sort(a, a+6);
    sort(b, b+4);

    do {
        do {
            vector<int> v(4, 0);
            partition(v, 0);
        }
        while (next_permutation(b, b+4));
    }
    while (next_permutation(a, a+6));

    cout << ans << '\n';

    return 0;
}