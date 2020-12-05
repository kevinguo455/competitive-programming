// https://dmoj.ca/problem/ccc11s4
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
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 10005;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    int blood[4][2];
    int patients[4][2];
    cin >> blood[0][0] >> blood[0][1] >> blood[1][0] >> blood[1][1] >> blood[2][0] >> blood[2][1] >> blood[3][0] >> blood[3][1];
    cin >> patients[0][0] >> patients[0][1] >> patients[1][0] >> patients[1][1] >> patients[2][0] >> patients[2][1] >> patients[3][0] >> patients[3][1];

    int c = 0;

    f(i,0,4){
        f(j,0,2){
            fr(x,i,-1){
                if (i == 2 && x == 1) continue;
                fr(y,j,-1){
                    int d = min(blood[x][y], patients[i][j]);
                    c += d;
                    blood[x][y] -= d;
                    patients[i][j] -= d;
                }
            }
        }
    }

    cout << c << endl;
    
    return 0;
}