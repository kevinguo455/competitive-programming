/*
CCC '20 J3 - Art
Key Concepts: Implementation
https://dmoj.ca/problem/ccc20j3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    int minx = 101, miny = 101, maxx = -1, maxy = -1;

    for (int i = 0; i < n; i++) {
        string in; cin >> in;
        stringstream s(in);
        string t;
        getline(s, t, ',');
        minx = min(minx, stoi(t));
        maxx = max(maxx, stoi(t));
        getline(s, t, ',');
        miny = min(miny, stoi(t));
        maxy = max(maxy, stoi(t));
    }

    printf("%d,%d\n%d,%d\n", minx-1, miny-1, maxx+1, maxy+1);

    return 0;
}