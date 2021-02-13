/*
IOI '11 P3 - Rice Hub
Key Concepts: Binary Search, Sliding Window
https://dmoj.ca/problem/ioi11p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int besthub(int R, int L, int X[], ll B) {
    int bl = 1, br = R, n;
    while (bl != br) {
        n = (bl+br)/2 + 1;

        int l1 = 0, l2 = n/2, r1 = n/2, r2 = n;
        if (n % 2 == 1) r1++;

        ll lsum = 0, rsum = 0;
        for (int i = l1; i < l2; i++) lsum += X[i];
        for (int i = r1; i < r2; i++) rsum += X[i];

        while (r2 < R && rsum - lsum > B) {
            lsum += X[l2] - X[l1];
            rsum += X[r2] - X[r1];
            l1++; l2++;
            r1++; r2++;
        }
        if (rsum - lsum > B) br = n-1;
        else bl = n;
    }
    return bl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, L; ll B; cin >> R >> L >> B;
    int X[R];
    for (int i = 0; i < R; i++) cin >> X[i];
    cout << besthub(R, L, X, B) << '\n';

    return 0;
}
