/*
Another Contest 3 Problem 2 - Camelot
Key Concepts: Coordinate Rotation
https://dmoj.ca/problem/acc3p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5; 

struct Coord {
    int x, y;
    
    void r45() {
        int t = x-y;
        x = x+y;
        y = t;
    }
};

int N;
Coord arr[MAXN];

bool cmpX(Coord a, Coord b) {
    return a.x < b.x;
}

bool cmpY(Coord a, Coord b) {
    return a.y < b.y;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].x >> arr[i].y;
        arr[i].r45();
    }

    sort(arr, arr+N, cmpX);
    int xm = arr[N/2].x;
    sort(arr, arr+N, cmpY);
    int ym = arr[N/2].y;

    long long ans = 1e18;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if ((xm+dx + ym+dy) % 2 != 0) continue;
            long long score = 0;
            for (int i = 0; i < N; i++) {
                score += abs(arr[i].x - (xm+dx)) + abs(arr[i].y - (ym+dy));
            }
            ans = min(ans, score);
        }
    }
    
    cout << (long long) ceil(ans/2.0) << '\n';

    return 0;
}