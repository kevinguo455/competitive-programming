/*
Inaho IX
Key Concepts: Matrix Multiplication, Binary Exponentiation
https://dmoj.ca/problem/inaho9
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9+7; 

struct Matrix {

    int s;
    vector<vector<ll>> e;

    // init empty square matrix of size s
    Matrix(int s) : s(s) {
        vector<ll> v(s, 0);
        for (int i = 0; i < s; i++) {
            e.push_back(v);
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

    void multiply(Matrix m) {
        Matrix res(s);
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                for (int k = 0; k < s; k++) {
                    res.e[i][j] += (e[i][k] * m.e[k][j]) % MOD;
                    res.e[i][j] %= MOD;
                }
            }
        }
        copy(res);
    }

    void power(int p) {
        Matrix res(s);
        res.id();
        while (p > 0) {
            if (p & 1) {
                res.multiply(*this);
            }
            multiply(*this);
            p >>= 1;
        }
        copy(res);
    }

    // raises this matrix to the power (p-1)
    void decimalPower(string p) {
        Matrix tmp(s);
        Matrix res(s);
        res.id();
        bool subtractOne = 0;
        for (int digit = p.size()-1; digit >= 0; digit--) {
            
            if (!subtractOne) {
                p[digit]--;
                if (p[digit] < '0') p[digit] = '9';
                else subtractOne = 1;
            }

            if (p[digit] != '0') {
                tmp.copy(*this);
                tmp.power(p[digit]-'0');
                res.multiply(tmp);
            }
            power(10);
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

};

/*

Matrix Transformation:

|  1  |   | a1 a2 a3 ... an | ^ (Z-N)    | f(Z)   |
|  1  |   |  1  0  0 ... 0  |            | f(Z-1) |
|  1  |   |  0  1  0 ... 0  |        =   | f(Z-2) |
| ... |   |  0  0  1 ... 0  |            |  ...   |
|  1  |   |  ... ... ... 0  |            | f(Z-N) |

*/

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; 
    string z;
    cin >> n >> z;

    // initialize transformation matrix
    Matrix m(n);
    for (int i = 0; i < n; i++) cin >> m.e[0][i];    
    for (int i = 0; i < n-1; i++) m.e[i+1][i] = 1;

    // "binary" exponentiation
    m.decimalPower(z);

    // f(Z) is last row of matrix
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += m.e[n-1][i];
        ans %= MOD;
    }
    cout << ans << "\n";

    return 0;
}