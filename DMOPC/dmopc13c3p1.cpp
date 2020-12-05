// https://dmoj.ca/problem/dmopc13c3p1
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <tuple>

using namespace std;

int main() {
    string s;
    int x, y;
    int n, m;
    cin >> n >> m;
    map<int, queue<string> > docs;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        cin.ignore();
        getline(cin, s);

        map<int, queue<string> >::iterator it;
        it = docs.find(y);
        if (it == docs.end()) {
            queue<string> strs;
            strs.push(s);
            docs.insert( pair<int, queue<string> >(y, strs));
        }
        else {
            it->second.push(s);
        }
    }

    int j;
    cin >> j;
    map<int, queue<string> >::iterator it;
    it = docs.find(j);

    if (it == docs.end()) {
        return 0;
    }

    while (!it->second.empty()) {
        cout << it->second.front() << endl;
        it->second.pop();
    }

    return 0;
}