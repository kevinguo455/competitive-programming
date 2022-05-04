/*
Riolku's Mock CCC S2 - Keen Keener Sequence
Key Concepts: Implementation
https://dmoj.ca/problem/rccc1s2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
const int MAXN = 1501; 

int arr[MAXN];
map<ll, vector<pair<int, int>>> m;
int freq[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            m[(ll)arr[i]*arr[j]].push_back({i, j});
        }
    }

    ll ans = 0;
    for (pair<ll, vector<pair<int, int>>> p : m) {
        memset(freq, 0, sizeof freq);
        for (pair<int, int> a : p.second) {
            freq[a.fi]++;
            freq[a.se]++;
        }
        for (pair<int, int> a : p.second) {
            ans += p.se.size() - freq[a.fi] - freq[a.se] + 1;
        }
    }
    cout << ans*4 << '\n';

    return 0;
}