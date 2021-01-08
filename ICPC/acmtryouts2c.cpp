/*
University of Toronto ACM-ICPC Tryouts 2012 Problem 2C - Homemade Asteroids
Key Concepts: Geometry, Simulation
https://dmoj.ca/problem/acmtryouts2c
Solution by Kevin Guo
*/

#include <bits/stdc++.h>
using namespace std;

bool doubleEqual(double a, double b) {
    return abs(a - b) < 1e-3;
}

double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0; 
}

class Asteroid {
    public: bool destroyed;

    int x1, y1, x2, y2, x3, y3;
    int minx, miny, maxx, maxy;
    double area;
    
    public: Asteroid(int x1, int y1, int x2, int y2, int x3, int y3) {
        (*this).x1 = x1;
        (*this).y1 = y1;
        (*this).x2 = x2;
        (*this).y2 = y2;
        (*this).x3 = x3;
        (*this).y3 = y3;

        destroyed = 0;
        minx = min(min(x1, x2), x3);
        miny = min(min(y1, y2), y3);
        maxx = max(max(x1, x2), x3);
        maxy = max(max(y1, y2), y3);

        area = triangleArea(x1, y1, x2, y2, x3, y3);
    }

    // check if this asteroid intersects (x, y)
    void check(int x, int y) {
        if (destroyed) return;
        if (x < minx || x > maxx || y < miny || y > maxy) return;

        if (doubleEqual(area, 
            triangleArea(x, y, x2, y2, x3, y3)
            + triangleArea(x1, y1, x, y, x3, y3)
            + triangleArea(x1, y1, x2, y2, x, y))) destroyed = 1;
    }
};

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    int cases; cin >> cases;
    for (int casen = 0; casen < cases; casen++) {

        int asteroids, frames, x, y, dx, dy; 
        cin >> asteroids >> frames >> x >> y >> dx >> dy;

        // init asteroids
        vector<Asteroid> v;
        int x1, y1, x2, y2, x3, y3;
        for (int i = 0; i < asteroids; i++) {
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            v.emplace_back(x1, y1, x2, y2, x3, y3);
        }

        // simulate missle travel
        for (int i = 0; i <= frames; i++) {
            // check for collision with each asteroid
            for (int j = 0; j < (int) v.size(); j++) {
                v[j].check(x, y);
            }
            x += dx;
            y += dy;
        }

        // count destroyed asteroids
        int ans = 0;
        for (int i = 0; i < (int) v.size(); i++) {
            if (v[i].destroyed) ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}