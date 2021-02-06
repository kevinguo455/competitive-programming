/*
CCC '05 S3 - Quantum Operations
Key Concepts: Implementation
https://dmoj.ca/problem/ccc05s3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f; 

vector<vector<int>> read() {
    int r; int c;
    cin >> r >> c;
    vector<vector<int>> out;
    for (int i = 0; i < r; i++) {
        vector<int> v;
        for (int j = 0; j < c; j++) {
            int x; cin >> x;
            v.push_back(x);
        }
        out.push_back(v);
    }
    return out;
}

vector<vector<int>> tensor(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> out;
    for (int ar = 0; ar < a.size(); ar++) {
        for (int br = 0; br < b.size(); br++) {
            vector<int> v;
            for (int ac = 0; ac < a[0].size(); ac++) {
                for (int bc = 0; bc < b[0].size(); bc++) {
                    v.push_back(a[ar][ac] * b[br][bc]);
                }
            }
            out.push_back(v);
        }
    }
    return out;
}

void eval(vector<vector<int>> v) {
    int min_ele = INF;
    int max_ele = -INF;
    int min_row = INF;
    int max_row = -INF;
    int min_col = INF;
    int max_col = -INF;

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            min_ele = min(min_ele, v[i][j]);
            max_ele = max(max_ele, v[i][j]);
        }
    }

    for (int i = 0; i < v.size(); i++) {
        int row = 0;
        for (int j = 0; j < v[0].size(); j++) {
            row += v[i][j];
        }
        min_row = min(min_row, row);
        max_row = max(max_row, row);
    }
    
    for (int j = 0; j < v[0].size(); j++) {
        int col = 0;
        for (int i = 0; i < v.size(); i++) {
            col += v[i][j];
        }
        min_col = min(min_col, col);
        max_col = max(max_col, col);
    }

    cout << max_ele << "\n" << min_ele << "\n" << max_row << "\n" << min_row << "\n" << max_col << "\n" << min_col << "\n";
}

void print(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n" << flush;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<vector<int>> v = read();
    for (int i = 1; i < n; i++) {
        vector<vector<int>> t = read();
        v = tensor(v, t);
    }
    
    eval(v);

    return 0;
}