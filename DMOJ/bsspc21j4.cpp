/*
BSSPC '21 J4 - James's Magical Soups
Key Concepts: Greedy Algorithms
https://dmoj.ca/problem/bsspc21j4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+5; 

struct Bowl{int a, b;} bowls[MAXN];

bool cmp(Bowl a, Bowl b) {
    if (a.a == b.a) return a.b < b.b;
    else return a.a < b.a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int X, N; cin >> X >> N;
    for (int i = 0, T, F; i < N; i++) {
        cin >> T >> F;
        bowls[i].a = max(0, T-X);
        bowls[i].b = F;
    }
    
    sort(bowls, bowls + N, cmp);

    int current_bowl = 0;
    priority_queue<int, vector<int>, greater<int>> expire;
    int ans = 0;

    for (int t = 0; t < MAXN; t++) {
        while (current_bowl < N && bowls[current_bowl].a == t) {
            if (bowls[current_bowl].b >= t) 
                expire.push(bowls[current_bowl].b);
            current_bowl++;
        }
        if (!expire.empty()) {
            while (expire.top() < t) expire.pop();
            expire.pop();
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}