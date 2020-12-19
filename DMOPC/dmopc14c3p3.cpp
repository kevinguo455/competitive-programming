/*
DMOPC '14 Contest 3 P3 - Not Enough Personnel!
Key Concepts: Implementation (Maps)
https://dmoj.ca/problem/dmopc14c3p3
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

    map<int, string> employees;
    string name; int skill, adapt;

    int n; cin >> n;
    f(i,0,n){
        cin >> name >> skill;
        if (employees.find(skill) == employees.end()) 
            employees[skill] = name;
    }
    int q; cin >> q;
    f(i,0,q){
        cin >> skill >> adapt;
        map<int, string>::iterator it = employees.lower_bound(skill);
        if (it == employees.end() || it->fi - skill > adapt) 
            cout << "No suitable teacher!\n";
        else cout << it->se << "\n";
    }

    return 0;
}