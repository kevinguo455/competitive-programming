/*
CCC '12 S3 - Absolutely Acidic
Key Concepts: Implementation
https://dmoj.ca/problem/ccc12s3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define fio cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)
const int MAXN = 1001; 

struct Freq{int n, f;};

vector<Freq> v(MAXN);

bool cmp(Freq a, Freq b) {
    if (a.f == b.f) return a.n < b.n;
    return a.f > b.f;
}

int main() {
    fio;

    for (int i = 0; i < MAXN; i++) {
        v[i] = {i, 0};
    }
    
    int n, x; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v[x].f++;
    }

    sort(v.begin(), v.end(), cmp);
    int c1 = 1, c2 = 1;
    bool second = 0;
    for (int i = 1; i < n; i++) {
        if (v[i].f != v[i-1].f) {
            if (second) break;
            second = 1;
        }
        else {
            if (second) c2++;
            else c1++;
        }
    }

    if (c1 == 1) {
        if (c2 == 1) cout << abs(v[0].n - v[c1].n) << "\n";
        else cout << max(abs(v[0].n - v[c1].n), abs(v[0].n - v[c1+c2-1].n)) << "\n";
    }
    else {
        cout << abs(v[0].n - v[c1-1].n) << "\n";
    }

    return 0;
}