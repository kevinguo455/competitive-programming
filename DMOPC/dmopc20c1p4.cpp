// https://dmoj.ca/problem/dmopc20c1p4
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 105; //100005

struct Matrix {
    vector<vll> e;   // elements
    int s;          // size
    
    Matrix() {}             // blank constructor
    Matrix(int size): s(size) { 
        f(i,0,s){           // constructor with init size
            vll v(s, 0);
            e.pb(v);
        }
    }
    void ss(int size) {     // sets size of matrix and initializes it with 0s
        s = size;
        e.clear();
        f(i,0,s){
            vll v(s, 0);
            e.pb(v);
        }
    }
    void print() {          // prints this matrix
        f(i,0,s){
            f(j,0,s) cout << e[i][j] << " ";
            cout << endl;
        }
    }
    void identity() {     // turns this matrix into an identity matrix
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
    void multiply(Matrix m) {   // multiplies this matrix by matrix m
        Matrix res(s);
        f(i,0,s){
            f(j,0,s){
                res.e[i][j] = 0;
                f(k,0,s) res.e[i][j] = (res.e[i][j] + (e[i][k] * m.e[k][j]) % MOD) % MOD;
            }
        }
        copy(res);
    }
    void power(ll p) {          // raises this matrix to the power of p using binary exponentiation
        Matrix res(s); 
        res.identity();
        Matrix a(s);
        a.copy(*this);
        while (p > 0) {            
            if (p & 1) {
                res.multiply(a);
            }
            a.multiply(a);
            p = p >> 1;
        }
        copy(res);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    int k, t, c; cin >> n >> k >> t >> c;

    Matrix m(t+1);
    m.e[0][t] = k;
    m.e[t][t] = 1;
    f(i,0,t){
        f(j,0,t){
            if (i == j) m.e[i+1][j] = 1;
            else m.e[i+1][j] = 0;
        } 
    }
    m.power(n-1);
    
    ll sum = 0;
    f(i,0,t) sum = (sum + m.e[i][t]) % MOD;
    sum = (sum + 2 * m.e[t][t]) % MOD;
    sum = (sum * c) % MOD;

    cout << sum << endl;  

    return 0;
}
