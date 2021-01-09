// This is my standard template for solving competitive programming problems.
// It includes shortcuts to speed up implementation, as well as some common pre-written algorithms.
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
#define fi first
#define se second
#define fio cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5; 

// another template matrix: DMOJ/inaho9.cpp
struct Matrix {
    vector<vll> e;  // elements
    int s;          // size
    
    Matrix() {}                 // blank constructor
    Matrix(int size): s(size) { // constructor with init size
        f(i,0,s){               
            vll v(s, 0);
            e.pb(v);
        }
    }
    void set_begin() {

    }
    void set_empty(int size) {  // sets size of matrix and initializes it with 0s
        s = size;
        e.clear();
        f(i,0,s){
            vll v(s, 0);
            e.pb(v);
        }
    }
    void set_identity() {       // turns this matrix into an identity matrix
        f(i,0,s){
            f(j,0,s){
                if (i == j) e[i][j] = 1;
                else e[i][j] = 0;                
            }
        }
    }
    void copy(Matrix m) {       // copies matrix m into this matrix
        f(i,0,s) f(j,0,s) e[i][j] = m.e[i][j];
    }
    void copy(vector<vi> v) {   // copies 2D vector of int into this matrix
        f(i,0,s) f(j,0,s) e[i][j] = v[i][j];
    }
    Matrix operator*(Matrix m) {   // multiplies this matrix by matrix m
        Matrix res(s);
        f(i,0,s){
            f(j,0,s){
                res.e[i][j] = 0;
                f(k,0,s) res.e[i][j] = (res.e[i][j] + (e[i][k] * m.e[k][j]) % MOD) % MOD;
            }
        }
        return res;
    }
    void operator=(const Matrix &m) {
        f(i,0,s){
            f(j,0,s){
                e[i][j] = m.e[i][j];
            }
        }
    }
    void power(ll p) {          // raises this matrix to the power of p using binary exponentiation
        Matrix res(s); 
        res.set_identity();
        Matrix a(s);
        a.copy(*this);
        while (p > 0) {            
            if (p & 1) {
                res = res * a;
            }
            a = a * a;
            p = p >> 1;
        }
        copy(res);
    }
    void print() {          // prints this matrix
        f(i,0,s){
            f(j,0,s) cout << e[i][j] << " ";
            cout << endl;
        }
    }
};

/* 
struct Edge{int n, w;};
bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}
priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> pq(cmp);
*/

int min3(int a, int b, int c) {
    return min(a, min(b, c));
}

int max3(int a, int b, int c) {
    return max(a, max(b, c));
}

int binarySearch(vi v, int n) { // returns the index of an element in a vector, or returns -1 if the elemnt is not in the vector
    int l = 0, r = v.size()-1, m;
    while (l <= r) {
        m = (l+r)/2;
        if (n > v[m]) l = m+1;          // move left pointer
        else if (n < v[m]) r = m-1;     // move right pointer
        else return m;  // if found
    }
    return -1;          // if not found
}

int lowerBound(vi v, int n) {   // returns the index of the first element that does not come before n (>= n)
    int l = 0, r = v.size(), m;     // returns the beyond-the-end element if all elements come before n
    while (l < r) {
        m = (l+r)/2;
        if (v[m] < n) l = m+1;      // move left pointer 
        else r = m;                 // move right pointer
    } 
    return l;
}

int upperBound(vi v, int n) {   // returns the index of the first element that comes after n (> n)
    int l = 0, r = v.size(), m;     // returns the beyond-the-end element if all elements come before n
    while (l < r) {
        m = (l+r)/2;
        if (v[m] <= n) l = m+1;     // move left pointer
        else r = m;                 // move right pointer
    }
    return l;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    return 0;
}