/*
CCC '16 S4 - Combining Riceballs
Key Concepts: Dynamic Programming (interval), Prefix Sum Array
https://dmoj.ca/problem/ccc16s4
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 405; 

int psa[MAXN];
bool dp[MAXN][MAXN];

int sum(int l, int r){    // sum inclusive from l to r
    return psa[r+1] - psa[l];
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    // init
    int n; cin >> n;
    f(i,0,n){
        cin >> psa[i+1];
        psa[i+1] += psa[i];
        dp[i][i] = 1;
    }
    // interval dp
    f(s,0,n){                   // size
        f(l,0,n-s){             // left bound = l, right bound = l+s (inclusive)
            int a = l, b = l+s; // two ptrs: left divider a, right divider b
            while (a < b) {
                if (sum(l,a) < sum(b,l+s)) a++;
                else if (sum(l,a) > sum(b,l+s)) b--;
                else if ((b - a == 1 && dp[l][a] && dp[b][l+s]) || (dp[l][a] && dp[a+1][b-1] && dp[b][l+s])) {
                    dp[l][l+s] = 1;
                    a++;
                }
                else a++;
            }
        }
    }
    // determine max
    int c = 0;
    f(l,0,n){
        f(r,l,n){
            if (dp[l][r]) c = max(c, sum(l,r));
        }
    }
    cout << c << endl;
    return 0;
}