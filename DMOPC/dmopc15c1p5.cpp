// https://dmoj.ca/problem/dmopc15c1p5
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
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 255; 

int p[MAXN][MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int r, c, a, x; cin >> c >> r >> a;
    f(i,0,r){
        f(j,0,c){
            cin >> x;
            p[i+1][j+1] += p[i+1][j];
            p[i+1][j+1] += p[i][j+1];
            p[i+1][j+1] -= p[i][j];
            p[i+1][j+1] += x;
        }
    }
    int mv = 0;
    f(h,1,r+1){
        int w = min(a/h,c);
        f(i,0,r-h+1){
            f(j,0,c-w+1){
                mv = max(mv, p[i+h][j+w] - p[i][j+w] - p[i+h][j] + p[i][j]);
                //cout << h << " " << w << "   ";
                //cout << i << " " << j << "  " << i+h << " " << j+w << "    " << p[i+h][j+w] << " -" << p[i][j+w] << " -" << p[i+h][j] << " " << p[i][j] << "    " << p[i+h][j+w] - p[i][j+w] - p[i+h][j] + p[i][j] << endl;
            }
        }
    }
    cout << mv << endl;
    return 0;
}