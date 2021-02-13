// https://dmoj.ca/problem/ccc04s3
#include <bits/stdc++.h>
using namespace std;

vector<int> arr[90];
int val[90];
bool vis[90];

int eval(int n) {
    if (arr[n][0] == -1)
        return val[n];
    if (vis[n]) 
        return -1;

    int sum = 0;
    vis[n] = 1;
    for (int i:arr[n]) { //dfs
        int x = eval(i);
        if (x == -1) 
            return -1;
        sum += x;
    }
    vis[n] = 0;
    arr[n].clear(); //index vals
    arr[n].push_back(-1);
    val[n] = sum;
    return sum;
}

bool isNum(string s) {
    for (unsigned int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

int loc(char* l) { //A1 --> 0
    return (l[0] - 'A')*9 + (l[1] -'1');
}

int main() {
    string str;
    for (int i = 0; i < 90; i++) { //define
        cin >> str;
        char* s = &str[0];
        char* next;
        if (isNum(s)) {
            arr[i].push_back(-1); //add to root
            val[i] = atoi(s);
        }
        else {
            next = strtok(s, "+");  //parse
            while (next != NULL) {
                arr[i].push_back(loc(next));
                next = strtok(NULL, "+");
            }
        }
    }
    for (int i = 0; i < 90; i++) { //execute
        int x = eval(i); 
        if (x == -1)
            cout << "*";
        else
            cout << x;

        if (i%9 == 8) 
            cout << endl;
        else
            cout << " ";        
    }
    return 0;
}
