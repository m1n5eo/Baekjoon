#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, max_dp = 0;
    int arr[222], dp[222] = {0, };

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];

        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }

        if(dp[i] == 0) dp[i] = 1;

        max_dp = max(max_dp, dp[i]);
    }

    cout << n-max_dp;

    return 0;
}