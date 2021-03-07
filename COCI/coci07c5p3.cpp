/*
COCI '07 Contest 5 #3 Jabuke
Key Concepts: Geometry (shoelace formula)
https://dmoj.ca/problem/coci07c5p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

struct Point {int x, y;};

int area(Point a, Point b, Point c) {   // returns double the area of triangle ABC
    return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));  // shoelace 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    Point a, b, c, p;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    
    int T = area(a, b, c);

    int N; cin >> N;
    int ans = 0;
    while (N--) {
        cin >> p.x >> p.y;
        if (area(a, b, p) + area(a, p, c) + area(p, b, c) == T) ans++;
    }
    printf("%.1f\n%d", T/2.0, ans);

    return 0;
}