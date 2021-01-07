/*
AtCoder Beginner Contest 187 Problem B - Gentle Pairs 
Key Concepts: Implementation
https://atcoder.jp/contests/abc187/tasks/abc187_b
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

struct Coord{int x, y;};

bool good(Coord a, Coord b) {
    return (abs((double)(a.y-b.y)/(a.x-b.x)) <= 1);
}

int main() {
    int n, x, y; cin >> n;
    vector<Coord> v;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        Coord b = {x, y};
        
        for (Coord a:v) if (good(a,b)) ans++;

        v.push_back(b);
    }
    cout << ans << "\n";
    return 0;
}