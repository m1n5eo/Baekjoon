#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int n, arr[55];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n, compare);
    if(n%2) cout << arr[n/2]*arr[n/2];
    else cout << arr[n/2-1]*arr[n/2];
}