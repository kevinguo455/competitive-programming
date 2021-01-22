/*
Back To School '18: The Golden Porcupine
Key Concepts: Data Structures (difference array), Intermediate Math (1st and 2nd differences of quadratic)
https://dmoj.ca/problem/bts18p6
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+5;

ll arr[MAXN][3];
int Q, N;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> Q >> N;

    ll l, r, a, b, c;
    for (int i = 0; i < Q; i++) {
        cin >> l >> r >> a >> b >> c;        
        ll s = (r-l);

        arr[l][0] += c;
        arr[l+1][1] += a + b;
        arr[l+2][2] += 2*a;
        arr[r+1][0] -= a*s*s + b*s + c;
        arr[r+1][1] -= 2*a*s - a + b;
        arr[r+1][2] -= 2*a;
    }

    for (int i = 1; i <= N; i++) {
        arr[i][2] += arr[i-1][2];
        arr[i][1] += arr[i-1][1] + arr[i][2];
        arr[i][0] += arr[i-1][0] + arr[i][1];

        cout << arr[i][0] << " ";
    }

    cout << "\n";

    return 0;
}