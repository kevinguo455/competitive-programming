/*
ACSL 2020-2021 Contest 3, Senior Division - Multiple Arrays
Key Concepts: Implementation
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 16;

int val[MAXN][MAXN][MAXN];
int minval[MAXN][MAXN];
bool vis[MAXN][MAXN];

int R, C, N;

struct Loc {
    int v, r, c;
    bool operator<(const Loc &l) {
        return v > l.v;
    }
};

// char to int conversion
inline int n(char c) {
    return c - '0';
}

bool inr(int r, int c) {
    return (r >= 0 && c >= 0 && r < R && c < C);
}

int eval(int r, int c) {
    if (vis[r][c]) return 0;
    vis[r][c] = 1;

    vector<Loc> v;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) continue;
            int tr = r + dr, tc = c + dc;
            if (!inr(tr, tc)) continue;

            for (int i = 0; i < N; i++) {
                v.push_back({val[tr][tc][i], tr, tc});
            }
        }
    }    

    sort(v.begin(), v.end());
    set<int> s, excl;
    for (int i = 0; i < v.size(); i++) {
        if (s.find(v[i].v) != s.end()) excl.insert(v[i].v);
        else s.insert(v[i].v);
    }
    for (int i = 0; i < v.size(); i++) {
        if (excl.find(v[i].v) == excl.end()) {
            return minval[r][c] + eval(v[i].r, v[i].c);
        }
    }
}

int sumOfMinAlongPath(string dim, vector<string> arrays) {
    R = n(dim[0]);
    C = n(dim[2]);
    N = arrays.size();

    memset(minval, 0x3f, sizeof minval);

    // build arrays of min across all arrays at each location
    for (int i = 0; i < N; i++) {
        stringstream ss(arrays[i]);
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                string s; ss >> s;
                val[r][c][i] = stoi(s);
                minval[r][c] = min(minval[r][c], val[r][c][i]);
            }
        }
    }

    return eval(0, 0);
}

int main() {

    while (true) {
        // read anoumt of arrays
        string dim; 
        getline(cin, dim);
        int N; N = n(dim[0]);

        // read dimension of arrays
        getline(cin, dim);
        
        // read data of arrays
        vector<string> arrays;
        arrays.resize(N);
        for (int i = 0; i < N; i++) getline(cin, arrays[i]);
        
        cout << sumOfMinAlongPath(dim, arrays) << endl;
    }

    return 0;
}

/*
SAMPLE INPUT
4
3 4
6 2 7 4 6 1 5 7 5 6 7 8
4 8 6 4 4 5 7 2 7 6 5 4
3 6 9 2 4 8 2 6 3 2 1 4
4 3 5 7 6 8 9 1 2 4 3 5
*/