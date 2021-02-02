/*
DMOPC '20 Contest 3 P2 - Bob and Parallel-Ks
Key Concepts: Implementation
https://dmoj.ca/problem/dmopc20c3p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Singer {
    vector<int> v;
    Singer() {}
};

bool cmp(int n, Singer a, Singer b) {
    return a.v[n] < b.v[n];
}

int M, N, K;
vector<Singer> singers;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> M >> N >> K;
    for (int i = 0; i < M; i++) {
        int x;
        singers.emplace_back();
        for (int j = 0; j < N; j++) {
            cin >> x;
            singers[i].v.push_back(x);
        }
    }

    ll ans = 0;
    unordered_map<int, Singer> m;

    for (int i = 0; i < N-1; i++) {
        m.clear();
        for (int j = 0; j < (int) singers.size(); j++) {
            m[singers[j].v[i]] = singers[j];
        }
        for (int j = 0; j < (int) singers.size(); j++) {
            auto it = m.find(singers[j].v[i] + K);
            if (it != m.end()) {
                if (singers[j].v[i+1] + K == it->second.v[i+1]) {
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}