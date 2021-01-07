/*
COCI '06 Contest 2 #5 Stol
Key Concepts: Prefix Sum Array
https://dmoj.ca/problem/coci06c2p5
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
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 405; 

int p[MAXN][MAXN]; // blocks in row

bool cl(int l, int r, int h) {
    if (p[h][r+1] == p[h][l]) return 1;
    return 0;
}

int per(int l, int w) {
    return 2*l + 2*w;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int r, c; cin >> r >> c;
    string s;
    f(i,0,r){
        cin >> s;
        f(j,0,c){
            if (s[j] == 'X') p[i+1][j+1]++;
            p[i+1][j+1] += p[i+1][j];
        }
    }
    int mp = 0;
    f(left,0,c){
        f(right,left,c){
            int ml = 0;
            f(h,0,r){
                if (cl(left,right,h+1)) {
                    ml++;
                    mp = max(mp, per(right-left+1,ml));
                }
                else ml = 0;
            }
        }
    }
    cout << mp-1 << endl;
    return 0;
}