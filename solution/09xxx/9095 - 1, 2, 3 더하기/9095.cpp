#include <bits/stdc++.h>
using namespace std;

int main() {
    int dp[12] = {0, 1, 2, 4, };
    for(int i = 4; i <= 11; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    int n, t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}
