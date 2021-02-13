/*
CCC '18 J3 - Are we there yet?
Key Concepts: Implementation
https://dmoj.ca/problem/ccc18j3
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 5; 

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int arr[MAXN];
    f(i,1,MAXN){
        cin >> arr[i];
        arr[i] += arr[i-1]; // rolling distance update from each city to first city
    }                       // (prefix sum array)
    f(i,0,MAXN){
        f(j,0,MAXN){
            cout << abs(arr[j]-arr[i]) << " ";
        }
        cout << endl;       // output absolute val of distance between every pair of cities i and j
    }

    return 0;
}