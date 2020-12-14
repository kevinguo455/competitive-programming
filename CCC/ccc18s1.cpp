/*
CCC '18 S1 - Voronoi Villages
Key Concepts: Implementation
https://dmoj.ca/problem/ccc18s1
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f * 2, MAXN = 5; 

int main() {
    fio;

    int n; cin >> n;
    vi v(n);
    f(i,0,n){
        cin >> v[i];    // construct sorted vector of all cities
    }
    vs(v);
    int md = INF;
    f(i,1,(int)v.size()-1) {
        md = min(md, v[i+1]-v[i-1]);    // find two closest cities
    }
    printf("%.1f\n", md/2.0);    // neighbourhood = half that distance

    return 0;
}