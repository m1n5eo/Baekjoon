#include <iostream>
#include <algorithm>
using namespace std;

#define NUM 1111

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, arr[NUM][NUM], dp[NUM][NUM] = {0, };

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!(i == 0)) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]+arr[i][j]);
            }
            if(!(i == 0) && !(j == 0)) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+arr[i][j]);
            }
            if(!(j == 0)) {
                dp[i][j] = max(dp[i][j], dp[i][j-1]+arr[i][j]);
            }
        }
    }

    cout << dp[n-1][m-1];

    return 0;
}