/*
VM7WC '16 #6 Bronze - The Most Important Skill in Biology
Key Concepts: Shoelace Formula
https://dmoj.ca/problem/vmss7wc16c6p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    int x0, y0; cin >> x0 >> y0;
    int x1 = x0, y1 = y0, x2, y2;

    int ans = 0;

    for (int i = 1; i < n; i++) {
        cin >> x2 >> y2;
        ans -= x1 * y2;
        ans += y1 * x2;
        x1 = x2; y1 = y2;
    }
    ans -= x1 * y0;
    ans += y1 * x0;

    cout << ceil(abs(ans)/2.0) << "\n";

    return 0;
}