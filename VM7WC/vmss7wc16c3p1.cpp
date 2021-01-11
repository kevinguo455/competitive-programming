/*
VM7WC '16 #3 Bronze - Shahir-in-a-Box
Key Concepts: Implementation
https://dmoj.ca/problem/vmss7wc16c3p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    int x, y, minx, miny; cin >> minx >> miny;
    int maxx = minx;
    int maxy = miny;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        minx = min(minx, x);
        miny = min(miny, y);
        maxx = max(maxx, x);
        maxy = max(maxy, y);
    }
    cout << (maxx-minx) * (maxy-miny) << "\n";

    return 0;
}