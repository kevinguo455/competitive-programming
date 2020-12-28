/*
Fianna Ray Ordesia
Key Concepts: Geometry
https://dmoj.ca/problem/stnbd5
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5; 

int main() {
    fio;

    double x1, y1, x2, y2, d; 
    cin >> x1 >> y1 >> x2 >> y2 >> d;

    // PAINNNNN
    if (y2 == y1) {     // edge case: the two points are on a vertical line
        double xn = (x1+x2)/2;
        
        double aq = 1;  // derived from distance formula
        double bq = -2*y1;
        double cq = -d*d + x1*x1 - 2*x1*xn + xn*xn + y1*y1;

        double discrim = bq*bq - 4*aq*cq;
        double yn1 = (-bq - sqrt(discrim)) / (2 * aq);
    
        printf("%.6f %.6f\n", xn, yn1);
        if (discrim != 0) {
            double yn2 = (-bq + sqrt(discrim)) / (2 * aq);
            printf("%.6f %.6f\n", xn, yn2);
        }
        return 0;
    }

    // equation of perpendicular
    double m = -(x2 - x1) / (y2 - y1); 
    double b = (y1+y2)/2 - m * (x1+x2)/2;

    // p a i n
    double aq = m*m + 1;    // derived from distance formula
    double bq = -2*x1 - 2*m*(y1-b);
    double cq = -d*d + x1*x1 + (y1-b)*(y1-b);

    double discrim = bq*bq - 4*aq*cq;
    double xn1 = (-bq - sqrt(discrim)) / (2 * aq);
    
    printf("%.6f %.6f\n", xn1, m * xn1 + b);
    if (discrim != 0) {
        double xn2 = (-bq + sqrt(discrim)) / (2 * aq);
        printf("%.6f %.6f\n", xn2, m * xn2 + b);
    }

    return 0;
}