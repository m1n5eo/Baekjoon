#include <bits/stdc++.h>

using namespace std;

int arr[1003], sum[1003];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr+n);
    if(arr[0] > 1) {
        printf("1");
        return 0;
    }
    sum[0] = arr[0];
    for(int i = 1; i < n; i++) {
        sum[i] = sum[i-1] + arr[i];
        if(arr[i+1] - sum[i] > 1) { // 1 0 -1 -2 -3 -4
            printf("%d", sum[i]+1);
            return 0;
        }
    }
    printf("%d", sum[n-1]+1);
}