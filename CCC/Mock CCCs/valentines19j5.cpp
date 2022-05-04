/*
Valentine's Day '19 J5 - Falling in Love
Key Concepts: Simple Math (equations of lines, complementary counting)
https://dmoj.ca/problem/valentines19j5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

struct hash_pair {
    template <class T1, class T2> size_t operator () (const pair<T1, T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N; cin >> N;
    unordered_map<int, int> slopes;
    unordered_map<pii, int, hash_pair> lines;
    ll ans = (N*N - N) / 2;

    for (int i = 0, m, b; i < N; i++) {
        cin >> m >> b;
        ans -= slopes[m]++ - lines[{m,b}]++;
    }

    cout << ans << '\n';

    return 0;
}