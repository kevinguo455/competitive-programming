/*
CCC '18 J4/S2 - Sunflowers
Key Concepts: Implementation
https://dmoj.ca/problem/ccc18s2
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 101; 

int arr[MAXN][MAXN];    // original matrix
int out[MAXN][MAXN];    // rotated matrix

int main() {
    fio;

    int s; cin >> s;
    f(i,0,s){
        f(j,0,s){
            cin >> arr[i][j];
        }
    }

    if (arr[0][0] <= arr[0][s-1] && arr[0][0] <= arr[s-1][0] && arr[0][0] <= arr[s-1][s-1]) {               // no rotation
        f(i,0,s){
            f(j,0,s){
                out[i][j] = arr[i][j];
            }
        }
    }
    else if (arr[0][s-1] <= arr[0][0] && arr[0][s-1] <= arr[s-1][0] && arr[0][s-1] <= arr[s-1][s-1]) {      // 90deg clockwise
        f(i,0,s){
            f(j,0,s){
                out[i][j] = arr[j][s-i-1];
            }
        }
    }
    else if (arr[s-1][s-1] <= arr[0][0] && arr[s-1][s-1] <= arr[s-1][0] && arr[s-1][s-1] <= arr[0][s-1]) {  // 180deg clockwise
        f(i,0,s){
            f(j,0,s){
                out[i][j] = arr[s-i-1][s-j-1];
            }
        }
    }
    else if (arr[s-1][0] <= arr[0][0] && arr[s-1][0] <= arr[0][s-1] && arr[s-1][0] <= arr[s-1][s-1]) {     // 270deg clockwise
        f(i,0,s){
            f(j,0,s){
                out[i][j] = arr[s-j-1][i];
            }
        }
    }
    else cout << "?" << endl;

    f(i,0,s){
        f(j,0,s){
            cout << out[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}