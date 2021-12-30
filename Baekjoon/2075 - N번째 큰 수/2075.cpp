#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[2250001];

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n*n; i++) cin >> arr[k++];
    sort(arr, arr+n*n);
    printf("%d", arr[n*n-n]);
}