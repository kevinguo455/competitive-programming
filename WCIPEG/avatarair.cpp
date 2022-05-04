/*
PEG Test '14 - Air
Key Concepts: Graph Theory (Grid Walk)
https://dmoj.ca/problem/avatarair
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int grid[101][101];

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n,m;cin>>n>>m;
    string s;
    for (int i=0;i<n;i++) {
        cin >> s;
        for (int j=0;j<m;j++) {
            if (s[j] == '/') 
                grid[i][j] = 1;
            else if (s[j] == '\\') 
                grid[i][j] = -1;
        }
    }
    int r=0,c=0,d=0,t=0;
    while (r>=0 && c>=0 && r<n && c<m) {
        if (grid[r][c] == 1 && t%2==0 || grid[r][c] == -1 && t%2==1 ) {
            d=3-d;
        }
        else if (grid[r][c] == -1 && t%2==0 || grid[r][c] == 1 && t%2==1 ) {
            if (d<=1) d=1-d;
            else d=5-d;
        }
        if (d==0) {
            c++;
        }
        else if (d==1) {
            r++;
        }
        else if (d==2) {
            c--;
        }
        else if (d==3) {
            r--;
        }
        t++;
    }
    cout << t << endl;
    return 0; 
}