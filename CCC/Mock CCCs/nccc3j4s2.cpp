#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    int arr1[N];
    int arr2[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> arr1[j];
        nth_element(arr1, arr1+N/2, arr1+N);
        arr2[i] = arr1[N/2];
    }
    nth_element(arr2, arr2+N/2, arr2+N);
    cout << arr2[N/2] << '\n';

    return 0;
}