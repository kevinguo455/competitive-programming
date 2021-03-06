/*
2-Dimensional Range Minimum Query
Key Concepts: Data Structures (2D Sparse Table)
https://dmoj.ca/problem/2drmq
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001, MAXK = 10; 

int lg2[MAXN];
int st[MAXN][MAXK][MAXN][MAXK];

void init(vector<vector<int>> arr) {
    int N = (int)arr.size();

    // precompute logs base 2
    for (int i = 2; i < MAXN; i++) {
        lg2[i] = lg2[i/2]+1;
    }

    // 1 by 1 rectangles
    for (int ri = 0; ri < N; ri++) {
        for (int ci = 0; ci < N; ci++) {
            st[ri][0][ci][0] = arr[ri][ci];
        }
    }

    // 1 by X rectangles
    for (int ri = 0; ri < N; ri++) {
        for (int cj = 1; cj <= lg2[N]; cj++) {
            for (int ci = 0; ci + (1<<cj) <= N; ci++) {
                st[ri][0][ci][cj] = min(st[ri][0][ci][cj-1], st[ri][0][ci+(1<<(cj-1))][cj-1]);
            }
        }
    }

    // X by X rectangles
    for (int rj = 1; rj <= lg2[N]; rj++) {
        for (int ri = 0; ri + (1<<rj) <= N; ri++) {
            for (int cj = 0; cj <= lg2[N]; cj++) {
                for (int ci = 0; ci + (1<<cj) <= N; ci++) {
                    st[ri][rj][ci][cj] = min(st[ri][rj-1][ci][cj], st[ri+(1<<(rj-1))][rj-1][ci][cj]);
                }
            }
        }
    }
}

int query(int r1, int r2, int c1, int c2) {
    int rk = lg2[r2-r1+1], rm = r2-(1<<rk)+1;
    int ck = lg2[c2-c1+1], cm = c2-(1<<ck)+1;
    return min(min(st[r1][rk][c1][ck], st[r1][rk][cm][ck]), 
               min(st[rm][rk][c1][ck], st[rm][rk][cm][ck]));
}



// ------- DEBUG CODE ------- // 

int N, Q;
vector<vector<int>> arr;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        arr[i].resize(N);
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    init(arr);

    cin >> Q;
    for (int i = 0, a, b, c, d; i < Q; i++) {
        cin >> a >> b >> c >> d;
        cout << query(a, b, c, d) << '\n';
    }

    return 0;
}