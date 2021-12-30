#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[1003], dp[1003];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++) dp[i] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    sort(dp, dp+n);

    printf("%d", dp[n-1]);
}