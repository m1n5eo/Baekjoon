#include <iostream>
#include <memory.h>
using namespace std;

#define MAX 1111
#define INF 1234567890

int n, arr[MAX][3], dp[MAX][3][3];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                dp[i][j][k] = INF;
            }
        }
    }

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][0][0] = arr[0][0];
    dp[0][1][1] = arr[0][1];
    dp[0][2][2] = arr[0][2];

    for(int k = 0; k < 3; k++) {
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                for(int t = -2; t <= 2; t++) {
                    if((0 <= j+t && j+t < 3) && t != 0) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][j+t][k]+arr[i][j]);
                    }
                }
            }
        }
    }
    
    int result1 = min(dp[n-1][1][0], dp[n-1][2][0]);
    int result2 = min(dp[n-1][0][1], dp[n-1][2][1]);
    int result3 = min(dp[n-1][0][2], dp[n-1][1][2]);

    cout << min(result1, min(result2, result3));
}