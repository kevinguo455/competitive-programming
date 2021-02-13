/*
CCC '09 S5 - Wireless
Key Concepts: Data Structures (Difference Array)
https://dmoj.ca/problem/ccc09s5
Solution by Kevin Guo
*/
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 30005; 

int xs, ys;       // max-x and max-y
int d[1005][MAXN];  // top-to-bottom vertical diff array

void u(int x, int y, int q){ // updates diff array, keeping into account range
    // fix bounds 
    if (x < 1 || x > xs+1) return;
    y = min(y, ys+1);
    y = max(y, 1);
    d[x][y] += q;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    cin >> ys >> xs;
    int n, x, y, r, b; cin >> n;
    f(i,0,n){
        cin >> x >> y >> r >> b;
        // diff array
        f(dx,0,r+1){
            int dy = floor(sqrt(r*r-dx*dx));
            // L = (x +- dx, y - dy), R = (x +- dx, y + dy)
            u(x+dx, y-dy, b);
            if (dx != 0) u(x-dx, y-dy, b);
            u(x+dx, y+dy+1, -b);
            if (dx != 0) u(x-dx, y+dy+1, -b);
        }
    }
    // scan for max vals
    int maxs = 0, maxc = 1;
    f(i,1,xs+1){
        int sn = 0;
        f(j,1,ys+1){
            sn += d[i][j];
            if (sn > maxs) {
                maxs = sn;
                maxc = 1;
            }
            else if (sn == maxs) maxc++;
        }
    }
    cout << maxs << endl << maxc << endl;
    return 0;
}