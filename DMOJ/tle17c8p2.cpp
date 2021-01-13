/*
TLE '17 Contest 8 P2 - Ship Defense
Key Concepts: Difference Array
https://dmoj.ca/problem/tle17c8p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
const int MAXD = 5, MAXN = 1005; 

pii modes[MAXD];
int diff[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    double h; int m, e; cin >> h >> m >> e;
    
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        modes[i] = {100-a, b};
    }

    // diff array
    int t, l, x;
    for (int i = 0; i < e; i++) {
        cin >> t >> l >> x;
        diff[t] += x;
        diff[t+l] -= x;
    }

    // simulate
    
    for (int i = 0; i < MAXN-2; i++) {
        double d = diff[i];
        for (int j = 0; j < m; j++) {
            d = min(d, (max(0, diff[i]-modes[j].se))*modes[j].fi/100.0);
        }
        h -= d;
        diff[i+1] += diff[i];
    }

    if (h <= 0) cout << "DO A BARREL ROLL!\n";
    else printf("%.2f\n", h);

    return 0;
}