/*
CCO '17 P4 - Rainfall Storage
Key Concepts: Dynamic Programming (golf)
https://dmoj.ca/problem/cco17p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 24403;

bitset<MAXN> ans; 

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vs(v); 
    vr(v);

    ans[0] = 1;
    set<int, greater<int>> s;

    // dp
    for (int pillar = 1; pillar < n; pillar++) {
        for (int val = MAXN; val >= 0; val--) {
            if (!ans[val]) continue;
            for (int delta : s) {
                if (delta <= v[pillar]) break;
                ans[val+delta-v[pillar]] = 1;
            }
        }
        s.insert(v[pillar]);
    }

    // output
    for (int i = 0; i < MAXN; i++) {
        if (ans[i]) cout << i << " ";
    }
    cout << "\n";

    return 0;
}