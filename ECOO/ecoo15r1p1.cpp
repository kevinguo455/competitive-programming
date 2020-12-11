/*
ECOO '15 R1 P1 - When You Eat Your Smarties
Key Concepts: Implementation, Simple Math
https://dmoj.ca/problem/ecoo15r1p1
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5; 

int main() {
    fio;
    f(cases,0,10){
        int c[8];
        ms(c,0);
        string s; getline(cin, s);
        while (s != "end of box") {
            if (s == "red") c[0]++;
            else if (s == "orange") c[1]++;
            else if (s == "yellow") c[2]++;
            else if (s == "green") c[3]++;
            else if (s == "blue") c[4]++;
            else if (s == "violet") c[5]++;
            else if (s == "pink") c[6]++;
            else if (s == "brown") c[7]++;
            getline(cin, s);
        }
        int n = c[0] * 16;
        f(i,1,8){
            n += 13 * ceil((double)c[i]/(double)7);
        }
        cout << n << endl;
    }

    return 0;
}