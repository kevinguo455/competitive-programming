/*
CCC '22 S1 - Good Groups
Key Concepts: Data Structures (set, map)
https://dmoj.ca/problem/ccc22s2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+5;

int pair_ab[MAXN], pair_ac[MAXN], pair_bc[MAXN];
set<int> no[MAXN];
queue<pair<int, int>> yes;

int cnt = 1;
unordered_map<string, int> ids;

int get_id(string name) {
    auto it = ids.find(name);
    if (it == ids.end()) {
        ids[name] = cnt; 
        ++cnt;
        return cnt-1;
    }
    return it->second;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int X, Y, G;
    cin >> X;
    for (int i = 0; i < X; ++i) {
        string s, t; cin >> s >> t;
        int id_a = get_id(s), id_b = get_id(t);
        yes.push({id_a, id_b});
    }
    cin >> Y;
    for (int i = 0; i < Y; ++i) {
        string s, t; cin >> s >> t;
        int id_a = get_id(s), id_b = get_id(t);
        no[id_a].insert(id_b);
        no[id_b].insert(id_a);
    }
    cin >> G;
    int ans = 0;
    for (int i = 0; i < G; ++i) {
        string s, t, u; cin >> s >> t >> u;
        int id_a = get_id(s), id_b = get_id(t), id_c = get_id(u);
        pair_ab[id_a] = id_b;
        pair_ac[id_a] = id_c;
        pair_bc[id_b] = id_c;

        // check for no
        if (no[id_a].find(id_b) != no[id_a].end()) ++ans;   // ab
        if (no[id_a].find(id_c) != no[id_a].end()) ++ans;   // ac
        if (no[id_b].find(id_c) != no[id_b].end()) ++ans;   // bc
    }

    // check for yes
    while (!yes.empty()) {
        int x = yes.front().first;
        int y = yes.front().second;
        yes.pop();

        if (pair_ab[x] != y && pair_bc[x] != y && pair_ac[x] != y
         && pair_ab[y] != x && pair_bc[y] != x && pair_ac[y] != x) ++ans;
    }

    cout << ans << '\n';

    return 0;
}