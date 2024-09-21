#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2100000000
#define MAX 11

int main() {
    FASTIO

    int n, m, space[MAX][MAX], dp[MAX][MAX][3];
    
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> space[i][j];

            if(i == 0) {
                for(int k = 0; k < 3; k++) {
                    dp[i][j][k] = space[i][j];
                }
            }
            else {
                for(int k = 0; k < 3; k++) {
                    dp[i][j][k] = INF;
                }
            }
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(j != 0) dp[i][j][0] = min(dp[i-1][j-1][1], dp[i-1][j-1][2]) + space[i][j];
            dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + space[i][j];
            if(j != m-1) dp[i][j][2] = min(dp[i-1][j+1][0], dp[i-1][j+1][1]) + space[i][j];
        }
    }

    int result = INF;

    for(int j = 0; j < m; j++) {
        for(int k = 0; k < 3; k++) {
            result = min(result, dp[n-1][j][k]);
        }
    }

    cout << result;
}