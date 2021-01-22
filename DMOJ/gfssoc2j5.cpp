/*
Nightmare-a-thon
Key Concepts: Data Structures (highly modified prefix sum array)
https://dmoj.ca/problem/gfssoc2j5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+5; 

int arr[MAXN];
int leftpeak[MAXN];
int rightpeak[MAXN];
int leftfreq[MAXN];
int rightfreq[MAXN];

int N, Q;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // find max vals and frequency 
    leftpeak[0] = arr[0];
    leftfreq[0] = 1;
    for (int i = 1; i < N; i++) {
        if (arr[i] > leftpeak[i-1]) {
            leftpeak[i] = arr[i];
            leftfreq[i] = 1;
        }
        else if (arr[i] == leftpeak[i-1]) {
            leftpeak[i] = arr[i];
            leftfreq[i] = leftfreq[i-1] + 1;
        }
        else {
            leftpeak[i] = leftpeak[i-1];
            leftfreq[i] = leftfreq[i-1];
        }
    }   
    
    rightpeak[N-1] = arr[N-1];
    rightfreq[N-1] = 1;
    for (int i = N-2; i >= 0; i--) {
        if (arr[i] > rightpeak[i+1]) {
            rightpeak[i] = arr[i];
            rightfreq[i] = 1;
        }
        else if (arr[i] == rightpeak[i+1]) {
            rightpeak[i] = arr[i];
            rightfreq[i] = rightfreq[i+1] + 1;
        }
        else {
            rightpeak[i] = rightpeak[i+1];
            rightfreq[i] = rightfreq[i+1];
        }
    }

    // answer queries
    int a, b;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b; a--; b--;
        if (a != 0 && (b == N-1 || leftpeak[a-1] > rightpeak[b+1])) {
            cout << leftpeak[a-1] << " " << leftfreq[a-1] << "\n";
        }
        else if (a == 0 || leftpeak[a-1] < rightpeak[b+1]) {
            cout << rightpeak[b+1] << " " << rightfreq[b+1] << "\n";
        }
        else {
            cout << leftpeak[a-1] << " " << leftfreq[a-1] + rightfreq[b+1] << "\n";
        }
    }

    return 0;
}