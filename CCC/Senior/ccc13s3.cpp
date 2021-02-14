/*
CCC '13 S3 - Chances of Winning
Key Concepts: Recursion
https://dmoj.ca/problem/ccc13s3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int F, G;
int ans;

map<int, pair<int, int>> m;

void score(vector<int> v) {
    vector<int> s(4, 0);
    for (int i = 0; i < (int)v.size(); i++) {
        int a = m[i].first;
        int b = m[i].second;
        if (v[i] == 1) s[a] += 3;
        if (v[i] == 2) s[a] += 1, s[b] += 1;
        if (v[i] == 3) s[b] += 3;
    }
    bool win = 1;
    for (int i = 0; i < 4; i++) {
        if (i == F) continue;
        if (s[i] >= s[F]) win = 0;
    }
    if (win) ans++;
}

void solve(vector<int> v, int idx) {
    if (idx == 6) {
        score(v);
        return;
    }
    if (v[idx] != 0) {
        solve(v, idx+1);
        return;
    }
    for (int i = 1; i <= 3; i++) {
        v[idx] = i;
        solve(v, idx+1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    m.insert({0, {0, 1}});
    m.insert({1, {0, 2}});
    m.insert({2, {0, 3}});
    m.insert({3, {1, 2}});
    m.insert({4, {1, 3}});
    m.insert({5, {2, 3}});

    cin >> F >> G; F--;
    vector<int> v(6, 0);
    for (int i = 0, a, b, sa, sb; i < G; i++) {
        cin >> a >> b >> sa >> sb;
        int r;
        if (sa > sb) r = 1;
        else if (sa == sb) r = 2;
        else r = 3;

        if (a == 1) {
            if (b == 2) v[0] = r;
            else if (b == 3) v[1] = r;
            else if (b == 4) v[2] = r;
        }
        else if (a == 2) {
            if (b == 3) v[3] = r;
            else if (b == 4) v[4] = r;
        }
        else if (a == 3) {
            if (b == 4) v[5] = r;
        }
    }

    solve(v, 0);
    cout << ans << '\n';

    return 0;
}