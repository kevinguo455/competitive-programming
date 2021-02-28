/*
CCC '10 S1 - Computer Purchase
Key Concepts: Implemnetation
https://dmoj.ca/problem/ccc10s1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

struct Computer {
    string name;
    int w;
    bool operator<(const Computer &c) {
        if (w == c.w) return name < c.name;
        return w > c.w;
    }
};

vector<Computer> v;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    while (N--) {
        string n;
        int r, s, d;
        cin >> n >> r >> s >> d;
        v.push_back({n, 2*r+3*s+d});
    }
    sort(v.begin(), v.end());
    if (v.size() > 0) cout << v[0].name;
    if (v.size() > 1) cout << '\n' << v[1].name;
    if (v.size() > 0) cout << '\n';

    return 0;
}