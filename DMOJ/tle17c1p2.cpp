/*
TLE '17 Contest 1 P2 - Willson and Food
Key Concepts: Implementation
https://dmoj.ca/problem/tle17c1p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

struct Event {
    int l, w;
    bool operator<(const Event e) {
        return l < e.l;
    }
};

map<string, int> val;
vector<Event> v;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T;
    string s; int x;
    for (int i = 0; i < T; i++) {
        cin >> s >> x;
        val[s] = x;
    }

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s >> x;
        v.push_back({x, val[s]});
    }
    sort(v.begin(), v.end());

    int loc = 0, energy = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        if (v[i].l - loc > max(0, energy)) break;
        energy -= v[i].l - loc;
        energy += v[i].w;
        loc = v[i].l;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}