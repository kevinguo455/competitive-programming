/*
CCC '06 S3 - Tin Can Telephone
Key Concepts: Geometry (Line Segment Intersection)
https://dmoj.ca/problem/ccc06s3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

struct Point{int x, y;};
struct Line{Point a, b;};

double triangleArea(Point a, Point b, Point c) { // (AB X AC) / 2
    return ((b.x-a.x)*(c.y-b.y) - (c.x-a.x)*(b.y-a.y))/2.0;
}

int dot(Line v, Line u) {
    return (v.b.x-v.a.x)*(u.b.x-u.a.x) + (u.b.y-u.a.y)*(v.b.y-v.a.y);
}

int cross(Line v, Line u) {
    return (v.b.x-v.a.x)*(u.b.y-u.a.y) - (u.b.x-u.a.x)*(v.b.y-v.a.y);
}

int orient(Point a, Point b, Point c) {
    int res = (b.y-a.y)*(c.x-b.x) - (c.y-b.y)*(b.x-a.x);
    if (res == 0) return res;   // 0 = collinear 
    return (res > 0 ? 1 : -1);  // 1 = clockwise, -1 = counterclockwise
}

bool inBounds(Point p, Line l) {    // is point p in the rectangle bounded by line l?
    return (min(l.a.x, l.b.x) <= p.x && p.x <= max(l.a.x, l.b.x) &&
            min(l.a.y, l.b.y) <= p.y && p.y <= max(l.a.y, l.b.y));
}

bool intersect(Line u, Line v) {    // touching = intersecting
    int uva = orient(u.a, u.b, v.a);
    int uvb = orient(u.a, u.b, v.b);
    int vua = orient(v.a, v.b, u.a);
    int vub = orient(v.a, v.b, u.b);
    if (uva == 0 && uvb == 0 && vua == 0 && vub == 0) { // check for overlapping parallel
        return (inBounds(u.a, v) || inBounds(u.b, v));
    }
    return (uva != uvb) && (vua != vub);
}

int main() {
    while (1) {
        Point a, b, c; cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        cout << triangleArea(a, b, c) << '\n' << flush;
        //Line v, u; cin >> v.a.x >> v.a.y >> v.b.x >> v.b.y >> u.a.x >> u.a.y >> u.b.x >> u.b.y;
        //cout << dot(v, u) << '\n' << flush;
    }
    cin.tie(0)->sync_with_stdio(0);

    Line L; cin >> L.a.x >> L.a.y >> L.b.x >> L.b.y;
    int N; cin >> N;
    int ans = 0;

    while (N--) {
        int s; cin >> s;
        if (s == 0) continue;
        
        bool touch = 0;
        Point f; cin >> f.x >> f.y;
        Point a, b; a.x = f.x; a.y = f.y;

        for (int i = 1; i < s; i++) {
            cin >> b.x >> b.y;
            touch = touch || intersect(L, {a, b});
            a.x = b.x; a.y = b.y;
        }

        if (touch || intersect(L, {f, a})) ans++;
    }

    cout << ans << '\n';

    return 0;
}