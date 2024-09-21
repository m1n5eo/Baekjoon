#include <bits/stdc++.h>
using namespace std;

int n, dp[50001] = {0, 1, };

int main() {
    for(int i = 2; i <= 50000; i++) {
        dp[i] = dp[i-1] + 1;
        for(int j = 2; j*j <= i; j++) {
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }

    cin >> n;
    cout << dp[n];
}