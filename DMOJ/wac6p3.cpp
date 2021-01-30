/*
Wesley's Anger Contest 6 Problem 3 - Difference Sorting
Key Concepts: Ad Hoc, Data Structures (Sparse Table)
https://dmoj.ca/problem/wac6p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5+5, MAXK = 18; 

vector<ll> v, s; 
unordered_map<ll, int> m;

ll st[MAXN][MAXK];
int lg2[MAXN];

// range max query from l to r
ll rmq(int l, int r) {
    int j = lg2[r-l+1];
    return max(st[l][j], st[r-(1<<j)+1][j]);
}

int main() {
    // precompute logs base 2
    for (int i = 2; i < MAXN; i++) {
        lg2[i] = lg2[i/2] + 1;
    }

    cin.tie(0)->sync_with_stdio(0);

    // init
    int n; cin >> n;
    ll a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
        s.push_back(a);
    }

    sort(s.begin(), s.end());

    // map elements in the nonsorted vector to elements in the sorted vector
    for (int i = 0; i < n; i++) {
        m[s[i]] = i;
    }

    // create difference array
    for (int i = 0; i < n-1; i++) {
        st[i][0] = s[i+1] - s[i];
    }

    // build sparse table
    for (int j = 1; j < MAXK; j++) {
        for (int i = 0; i + (1 << j) <= n-1; i++) {
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > s[i]) {
            ans = max(ans, rmq(m[s[i]], m[v[i]]-1));
        }
    }

    cout << ans << "\n";

    return 0;
}