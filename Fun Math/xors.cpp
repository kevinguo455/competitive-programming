// https://dmoj.ca/problem/xors
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n;
	long long int xsum = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> x; 
		sum += x;
		xsum ^= x;
	}
	cout << sum - xsum << endl;
	return 0;	
}