/*
CCC '00 S5 - Sheep and Coyotes
Key Concepts: Geometry
https://dmoj.ca/problem/ccc00s5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5; 

struct Sheep {
    double x, y;

    void eat() {
        printf("The sheep at (%.2f, %.2f) might be eaten.\n", x, y);
    }    

    double dist(Sheep s) {
        return sqrt((s.x-x)*(s.x-x) + s.y*s.y);
    }
};

bool cmpY(Sheep a, Sheep b) {
    return a.y < b.y;
}

vector<Sheep> v;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    double a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    //sort(v.begin(), v.end(), cmpY);
    
    for (int i = 0; i < N; i++) {
        bool eat = 1;
        for (int j = 0; j < N; j++) {
            if (v[i].dist(v[j]) < v[i].y) {
                eat = 0;
                break;
            }
        }
        if (eat) v[i].eat();
    }

    return 0;
}