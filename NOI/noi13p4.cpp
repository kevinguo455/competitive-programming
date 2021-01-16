/*
NOI '13 P4 - Matrix Game
Key Concepts: Matrix Multiplication, Binary Exponentiation
https://dmoj.ca/problem/noi13p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7; 

struct Matrix {
    ll arr[2][2];

    void init(int a, int b) {
        arr[0][0] = a;
        arr[0][1] = 0;
        arr[1][0] = b;
        arr[1][1] = 1;
    }

    void id() {
        arr[0][0] = 1;
        arr[0][1] = 0;
        arr[1][0] = 0;
        arr[1][1] = 1;
    }

    void copy(Matrix m) {
        arr[0][0] = m.arr[0][0];
        arr[0][1] = m.arr[0][1];
        arr[1][0] = m.arr[1][0];
        arr[1][1] = m.arr[1][1];
    }

    void multiply(Matrix m) {
        Matrix a;
        a.copy(*this);
        arr[0][0] = ((a.arr[0][0] * m.arr[0][0]) % MOD + (a.arr[0][1] * m.arr[1][0]) % MOD) % MOD;
        arr[0][1] = ((a.arr[0][0] * m.arr[0][1]) % MOD + (a.arr[0][1] * m.arr[1][1]) % MOD) % MOD;
        arr[1][0] = ((a.arr[1][0] * m.arr[0][0]) % MOD + (a.arr[1][1] * m.arr[1][0]) % MOD) % MOD;
        arr[1][1] = ((a.arr[1][0] * m.arr[0][1]) % MOD + (a.arr[1][1] * m.arr[1][1]) % MOD) % MOD;
    }

    void print() {
        cout << arr[0][0] << " " << arr[0][1] << "\n" << arr[1][0] << " " << arr[1][1] << "\n";
    }

    void power(int n) {
        Matrix a;
        a.copy(*this);
        (*this).id();

        while (n > 0) {
            if (n & 1) {
                (*this).multiply(a);
            }
            a.multiply(a);
            n >>= 1;
        }
    }

    void decimalPowerSubtractOne(string s) {
        Matrix a;
        a.copy(*this);
        (*this).id();

        bool subtractOne = false;

        for (int i = s.length()-1; i >= 0; i--) {
            if (!subtractOne) {
                s[i]--;
                if (s[i] < '0') s[i] = '9';
                else subtractOne = true;
            }
            if (s[i] != '0') {
                Matrix t;
                t.copy(a);
                t.power(s[i] - '0');
                (*this).multiply(t);
            }
            a.power(10);
        }
    }

};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string n, m; cin >> n >> m;
    int a, b, c, d; cin >> a >> b >> c >> d;

    Matrix row;
    row.init(a, b);
    row.decimalPowerSubtractOne(m);

    Matrix col;
    col.init(c, d);

    Matrix res;
    res.copy(row);
    res.multiply(col);

    res.decimalPowerSubtractOne(n);
    res.multiply(row);
    
    cout << (res.arr[0][0] + res.arr[1][0]) % MOD << "\n";

    return 0;
}