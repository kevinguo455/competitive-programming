/*
USACO 2020 December Contest, Silver - Problem 2. Rectangular Pasture
Key Concepts: Coordinate Compression, Prefix Sum Array
http://www.usaco.org/current/index.php?page=viewproblem&cpid=1051
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int x;  // starting x coord
    int y;  // starting y coord
};

bool cmpX(Cow a, Cow b) {
    return a.x < b.x;
}

bool cmpY(Cow a, Cow b) {
    return a.y < b.y;
}

const int MAXN = 2502; //2502

int arr[MAXN][MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    vector<Cow> v;

    // init
    int n, x, y; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }

    // coordinate compression
    sort(v.begin(), v.end(), cmpY);
    for (unsigned int i = 0; i < v.size(); i++) {
        v[i].y = i;
    }
    sort(v.begin(), v.end(), cmpX);
    for (unsigned int i = 0; i < v.size(); i++) {
        v[i].x = i;
        arr[i][v[i].y]++;
    }
    // generate 2D psa
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 && j == 0) continue;
            else if (i == 0) arr[i][j] += arr[i][j-1];
            else if (j == 0) arr[i][j] += arr[i-1][j];
            else arr[i][j] += arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1];
        }
    }
    
    long long s = 1;
    for (unsigned int l = 0; l < v.size(); l++) {
        for (unsigned int r = l; r < v.size(); r++) {
            int up = max(v[l].y,v[r].y);
            int down = min(v[l].y,v[r].y);
            int upc = arr[r][n] - arr[r][up] - arr[l][n] + arr[l][up];
            int downc = 0;
            if (down > 0) downc = arr[r][down-1] - arr[l][down-1];
            s += (upc + 1) * (downc + 1);
        }
    }

    cout << s << "\n";

    return 0;
}