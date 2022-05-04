/*
ECOO '18 R2 P2 - Homework
Key Concepts: Greedy Algorithms, Line Sweep
https://dmoj.ca/problem/ecoo18r2p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

struct Event {
    int t;
    double w;
    bool operator<(const Event &e) {
        return t > e.t;
    }
};

vector<Event> v;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(4);

    for (int cases = 0; cases < 10; cases++) {
        int N; cin >> N;
        v.clear();
        v.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i].t >> v[i].w;
        }
        v.push_back({0, 0});
        sort(v.begin(), v.end());
        
        priority_queue<double> pq;
        double ans = 0;
        pq.push(v[0].w);
        for (int i = 1; i <= N; i++) {
            for (int j = v[i].t; j < v[i-1].t; j++) {
                if (pq.empty()) break;
                ans += pq.top(); pq.pop();
            }
            pq.push(v[i].w);
        }

        cout << ans << '\n';
    }

    return 0;
}