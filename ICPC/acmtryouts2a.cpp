/*
University of Toronto ACM-ICPC Tryouts 2012 Problem 2A - The Super Mario Blues
Key Concepts: Implementation
https://dmoj.ca/problem/acmtryouts2a
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e3+5;

int l(string s){
    int a = s[0] - '0';
    int b = s[2] - '0';
    return a*4+b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    f(i,0,n){
        string s; cin >> s;
        int ln = l(s);
        int lc = 1;
        while (ln != l("8-4")){
            if (ln == l("1-2")) {
                ln = l("4-1");
            }
            else if (ln == l("4-2")) {
                ln = l("8-1");
            }
            else {
                ln++;
            }
            lc++;
        }
        cout << lc << endl;
    }
    return 0;
}