/*
A Coin Problem
Key Concepts: Dynamic Programming (Golf), Offline Processing
https://dmoj.ca/problem/acoinproblem
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3+5, MAXV = 1e4+5; 

struct Query{int w, n, id, ans;};

int arr[MAXN];
int dp[MAXV];
vector<Query> v;

bool cmpN(Query a, Query b) {
    return a.n < b.n;
}

bool cmpID(Query a, Query b) {
    return a.id < b.id;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, V; cin >> N >> V;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int w, n;
    for (int i = 0; i < V; i++) {
        cin >> w >> n;
        v.push_back({w, n, i});
    }
    sort(v.begin(), v.end(), cmpN);

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    int idx = 0;
    for (int c = 0; c < N; c++) {
        for (int i = 0; i + arr[c] < MAXV; i++) {
            dp[i + arr[c]] = min(dp[i + arr[c]], dp[i] + 1);
        }
        while (v[idx].n == c+1) {
            v[idx].ans = dp[v[idx].w];
            idx++;
        }
    }

    sort(v.begin(), v.end(), cmpID);
    for (Query q : v) {
        cout << (q.ans == 0x3f3f3f3f ? -1 : q.ans) << "\n";
    }

    return 0;
}