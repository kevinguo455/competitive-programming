/*
MWC '15 #2 P2: Towering Towers
Key Concepts: Implementation (Stack)
https://dmoj.ca/problem/mwc15c2p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

struct Tower{int h, l;};
  
stack<Tower> s;         

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, h; cin >> N;
    s.push({0x3f3f3f3f, 0});

    for (int l = 0; l < N; l++) {
        cin >> h;
        while (s.top().h <= h) s.pop();
        cout << l - s.top().l << ' ';
        s.push({h, l});
    }

    cout << '\n';

    return 0;
}