/*
CCC '21 J2 - Silent Auction
Key Concepts: Implementation
https://dmoj.ca/problem/ccc21j2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    int bid, maxbid = 0; 
    string name, winner;
    
    while (N--) {
        cin >> name >> bid;
        if (bid > maxbid) {
            maxbid = bid;
            winner = name;
        }
    }

    cout << winner << '\n';

    return 0;
}