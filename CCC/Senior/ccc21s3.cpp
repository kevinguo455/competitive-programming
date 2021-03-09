/*
CCC '21 S3 - Lunch Concert
Key Concepts: Ternary Search
https://dmoj.ca/problem/ccc21s3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Friend {
    int p, w, d;
};

int N;
vector<Friend> v;

ll eval(int p) {
    ll ans = 0;
    for (Friend f : v) {
        ans += (ll) max(abs(f.p-p)-f.d, 0) * f.w;
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i].p >> v[i].w >> v[i].d;
    
    int l = 0, r = 1e9;
    while (l < r - 2) {
        int m1 = ((ll) 2*l + r)/3;
        int m2 = (l + (ll) 2*r)/3;
        if (eval(m1) < eval(m2)) r = m2;
        else l = m1;
    }

    cout << min(eval(l), min(eval(l+1), eval(l+2))) << '\n';

    return 0;
}