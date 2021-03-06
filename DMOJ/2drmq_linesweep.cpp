/*
2-Dimensional Range Minimum Query
Key Concepts: Implementation (Line Sweep)
https://dmoj.ca/problem/2drmq
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001, MAXN2 = 1000001, PIVOT = 1200; 

struct Point {
    int val, r, c;
    bool operator<(Point &p) {
        return val < p.val;
    }
};
Point points[MAXN2];
int arr[MAXN][MAXN];

void init(vector<vector<int>> in) {
    int N = (int)in.size(), idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = in[i][j];
            points[idx++] = {in[i][j], i, j};
        }
    }
    sort(points, points + N*N);
}

int query(int r1, int r2, int c1, int c2) {
    if ((r2-r1)*(c2-c1) < PIVOT) {
        int ans = 1e9;
        for (int r = r1; r <= r2; r++) {
            for (int c = c1; c <= c2; c++) {
                ans = min(ans, arr[r][c]);
            }
        }
        return ans;
    }
    for (Point p : points) {
        if (r1 <= p.r && p.r <= r2 && c1 <= p.c && p.c <= c2) {
            return p.val;
        }
    }
    return 0;
}



// ------- DEBUG CODE ------- // 

int N, Q;
vector<vector<int>> in;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    in.resize(N);
    for (int i = 0; i < N; i++) {
        in[i].resize(N);
        for (int j = 0; j < N; j++) {
            cin >> in[i][j];
        }
    }

    init(in);

    cin >> Q;
    for (int i = 0, a, b, c, d; i < Q; i++) {
        cin >> a >> b >> c >> d;
        cout << query(a, b, c, d) << '\n';
    }

    return 0;
}