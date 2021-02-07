#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    nth_element(arr, arr+N/2, arr+N);
    if (N % 2 == 1) {
        cout << arr[N/2] << '\n';
    } 
    else {
        nth_element(arr, arr+N/2-1, arr+N/2);
        cout << round((arr[N/2-1] + arr[N/2])/2.0) << '\n';
    }

    return 0;
}