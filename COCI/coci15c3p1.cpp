/*
COCI '15 Contest 3 #1 Pot
Key Concepts: Simple Math, String Algorithms
https://dmoj.ca/problem/coci15c3p1
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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e2+5;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, x, c = 0; cin >> n;
    f(i,0,n){
        cin >> x;
        c += pow(x/10, x%10);
    }
    cout << c << endl;
    return 0;
}
