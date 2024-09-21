#include <bits/stdc++.h>
using namespace std;

int arr[303], dp[303];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];

    for(int i = 2; i < n; i++) {
        dp[i] = dp[i-2]+arr[i] > dp[i-3]+arr[i-1]+arr[i]? dp[i-2]+arr[i]:dp[i-3]+arr[i-1]+arr[i];
    }

    printf("%d", dp[n-1]);
}
