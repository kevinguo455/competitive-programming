/*
Rinslet Laurenfrost
Key Concepts: Greedy Algorithms
https://dmoj.ca/problem/stnbd3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = (int)a; i < (int)b; i++)
#define fr(i,b,a) for (int i = (int)b; i > (int)a; i--)
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 26; 

string a, b; 
int x[MAXN], y[MAXN];

int main() {
    fio;

    cin >> a >> b;

    f(i,0,a.length()) x[a[i]-'a']++;
    f(i,0,b.length()) y[b[i]-'a']++;

    int c = a.length() + b.length();
    f(i,0,MAXN) {
        c -= min(x[i], y[i]) * 2;
    }
    
    cout << c << "\n";

    return 0;
}