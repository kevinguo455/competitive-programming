/*
ECOO '14 R3 P3 - Future City
Key Concepts: Graph Theory (grid BFS)
https://dmoj.ca/problem/ecoo14r3p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+5, INF = 0x3f3f3f3f; 

int R, C, N, CASES = 10;

struct Point {int r, c;} S, F;
struct Coord {int dist; Point to;} grid[MAXN][MAXN];

inline bool equals(Point a, Point b) {
    return a.r == b.r && a.c == b.c;
}

inline bool inr(Point p) {
    return (p.r >= 0 && p.r < R && p.c >= 0 && p.c < C);
}

inline void search(Point c, Point t, deque<Point> &q) {
    if (inr(t) && grid[c.r][c.c].dist + 1 < grid[t.r][t.c].dist) {
        q.push_back(t);
        grid[t.r][t.c].dist = grid[c.r][c.c].dist + 1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (CASES--) {
        
        // Reset grid
        for (int r = 0; r < MAXN; r++) {
            for (int c = 0; c < MAXN; c++) {
                grid[r][c] = {INF, {-1, -1}};
            }
        }

        // Read input
        cin >> R >> C;
        cin >> S.r >> S.c >> F.r >> F.c;
        cin >> N;
        for (int i = 0, r1, c1, r2, c2; i < N; i++) {
            cin >> r1 >> c1 >> r2 >> c2;
            grid[r1][c1].to = {r2, c2};
            grid[r2][c2].to = {r1, c1};
        }

        // BFS
        deque<Point> q;
        q.push_back(S);
        grid[S.r][S.c].dist = 0;

        while (!q.empty()) {
            Point c = q.front(); q.pop_front();

            if (equals(c, F)) break; // Reached end

            // Search teleport
            #define tp grid[c.r][c.c].to

            if (tp.r != -1 && grid[c.r][c.c].dist < grid[tp.r][tp.c].dist) {
                q.push_front(tp);    // tp doesn't increase distance; push to front of deque
                grid[tp.r][tp.c].dist = grid[c.r][c.c].dist;
            }

            // Search adjacent 
            search(c, {c.r-1, c.c}, q);
            search(c, {c.r+1, c.c}, q);
            search(c, {c.r, c.c-1}, q);
            search(c, {c.r, c.c+1}, q);
     
        }

        cout << grid[F.r][F.c].dist << '\n' << flush;

    }

    return 0;
}