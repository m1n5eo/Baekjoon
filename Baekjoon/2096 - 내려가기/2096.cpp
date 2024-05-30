#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[111111][3], dp[2][2][3];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < 3; i++) {
        dp[0][1][i] = arr[0][i];
        dp[1][1][i] = arr[0][i];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            dp[0][0][j] = dp[0][1][j];
            dp[1][0][j] = dp[1][1][j];
        }

        dp[0][1][0] = arr[i][0] + max(dp[0][0][0], dp[0][0][1]);
        dp[0][1][1] = arr[i][1] + max(dp[0][0][1], max(dp[0][0][0], dp[0][0][2]));
        dp[0][1][2] = arr[i][2] + max(dp[0][0][2], dp[0][0][1]);

        dp[1][1][0] = arr[i][0] + min(dp[1][0][0], dp[1][0][1]);
        dp[1][1][1] = arr[i][1] + min(dp[1][0][1], min(dp[1][0][0], dp[1][0][2]));
        dp[1][1][2] = arr[i][2] + min(dp[1][0][2], dp[1][0][1]);
    }

    cout << max(dp[0][1][0], max(dp[0][1][1], dp[0][1][2])) << " ";
    cout << min(dp[1][1][0], min(dp[1][1][1], dp[1][1][2]));

    return 0;
}