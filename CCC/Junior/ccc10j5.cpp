// https://dmoj.ca/problem/ccc10j5
#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int> > q;
bool visited[64];

int coordToInt(int x, int y) {
    return (x-1) + 8*(y-1);
}

int main () {
    int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
    q.push(make_pair(x1,y1));
    int d = 0;
    while (!q.empty()) {
        int s = q.size();
        for (int i = 0; i < s; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop(); // get top element of q
            if (x < 1 || y < 1 || x > 8 || y > 8) { // out of bounds
                continue;
            }
            if (x == x2 && y == y2) {   // is final location
                cout << d << endl;
                return 0;
            }
            if (visited[coordToInt(x,y)]) { // location already visited
                continue;
            }
            visited[coordToInt(x,y)] = 1;   // ok great this location is valid!
            q.push(make_pair(x-2,y-1));
            q.push(make_pair(x-1,y-2));
            q.push(make_pair(x-2,y+1)); // add every possible move from this location
            q.push(make_pair(x-1,y+2));
            q.push(make_pair(x+2,y-1));
            q.push(make_pair(x+1,y-2));
            q.push(make_pair(x+2,y+1));
            q.push(make_pair(x+1,y+2));
        }
        d++;
    }
    cout << d << endl;
    return 0;
}