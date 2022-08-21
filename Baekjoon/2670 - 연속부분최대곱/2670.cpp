#include <iostream>
#include <cmath>
using namespace std;

int n;
double dp[10001], max_dp = -1;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> dp[i];
        if(i) dp[i] = max(dp[i], dp[i]*dp[i-1]);
        max_dp = max(max_dp, dp[i]);
    }
    max_dp = round(max_dp*1000) / 1000;

    cout << fixed;
    cout.precision(3);
    cout << max_dp;
}