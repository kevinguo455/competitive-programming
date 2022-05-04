/*
Bob's Coin Sequence
Key Concepts: Ad Hoc
https://dmoj.ca/problem/oly21practice11
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    v.push_back(-1);
    bool x, y; cin >> x;
    for (int i = 1; i < N; i++) {
        cin >> y;   
        if (x == y) v.push_back(i-1);
        x = y;
    }
    
    if (v.size() < 4) {
        cout << N << '\n';
        return 0;
    }
    v.push_back(N-1);
    
    int ans = 0;
    for (int l = 1; l + 2 < v.size(); l++) {
        int s = v[l+2] - v[l-1];
        ans = max(ans, s);
    }

    cout << ans << '\n';

    return 0;
}