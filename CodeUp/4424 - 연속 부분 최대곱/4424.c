#include <stdio.h>
#include <algorithm>

using namespace std;

double max(double x, double y) {
    return x > y? x:y;
}

int main() {
    int n;
    double arr[10003], dp[10003];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) dp[i] = 1;
    for(int i = 0; i < n; i++) scanf("%lf", &arr[i]);
    dp[0] = arr[0];

    for(int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] * arr[i], arr[i]);
    }

    sort(dp, dp+n);
    printf("%.3lf", dp[n-1]);
}