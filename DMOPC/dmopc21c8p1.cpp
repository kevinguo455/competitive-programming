/*
DMOPC '21 Contest 8 P1 - Peanut Planning
Key Concepts: Greedy Algorithms
https://dmoj.ca/problem/dmopc21c8p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;
    multiset<int> s;
    for (int i = 1, x; i <= N; ++i) {
        cin >> x;
        s.insert(x);
    }
    vector<int> ans;

    for (int i = 1; i <= N/2; ++i) {
        auto ita = s.begin();
        int a = *ita;
        ans.push_back(a);
        s.erase(ita);
        auto itb = s.lower_bound(M-a);
        if (itb == s.end()) {
            cout << "-1\n";
            return 0;
        }
        ans.push_back(*itb);
        s.erase(itb);
    }

    if (!s.empty()) ans.push_back(*(s.begin()));

    for (int i : ans) cout << i << ' ';
    cout << '\n';

    return 0;
}