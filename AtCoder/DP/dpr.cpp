/*
AtCoder Educational DP Contest Problem R - Walk
Key Concepts: Matrix Multiplication, Binary Exponentiation
https://dmoj.ca/problem/graph1p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

struct Matrix {
    int s;
    vector<vector<ll>> e;
    Matrix (int size): s(size) {
        e.resize(s);
        for (int i = 0; i < s; i++) { 
            e[i].resize(s);
        }
    }

    void read() {
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                cin >> e[i][j];
            }
        }
    }

    void id() {
        for (int i = 0; i < s; i++) {
            e[i][i] = 1;
        }
    }

    void copy(Matrix m) {
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                e[i][j] = m.e[i][j];
            }
        }
    }

    void mul(Matrix m) {
        Matrix res(s);
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                for (int k = 0; k < s; k++) {
                    res.e[i][j] = (res.e[i][j] + (e[k][j] * m.e[i][k]) % MOD) % MOD;
                }
            }
        }
        copy(res);
    }

    void pow(ll p) {
        Matrix res(s);
        res.id();
        while (p > 0) {
            if (p & 1) {
                res.mul(*this);
            }
            (*this).mul(*this);
            p /= 2;
        }
        copy(res);
    }

    void print() {
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                cout << e[i][j] << " ";
            }
            cout << "\n";
        }
    }

    int sum() {
        int ans = 0;
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                ans = (ans + e[i][j]) % MOD;
            }
        }
        return ans;
    }

};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; ll K; cin >> N >> K;
    Matrix m(N);
    m.read();
    m.pow(K);
    cout << m.sum() << "\n";

    return 0;
}