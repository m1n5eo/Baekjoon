#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1e9
#define MAX 1111

int n, m;
vector<vector<int>> robot(MAX, vector<int>(MAX, 0));
vector<vector<int>> dp(MAX, vector<int>(MAX, 0));

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> robot[i][j];
        }
    }

    for(int j = 1; j <= m; j++) {
        dp[1][j] = robot[1][j] + dp[1][j-1];
    }

    for(int i = 2; i <= n; i++) {
        vector<int> temp1(m+1, -INF), temp2(m+1, -INF);

        temp1[1] = dp[i-1][1] + robot[i][1];
        temp2[m] = dp[i-1][m] + robot[i][m];

        for(int j = 2; j <= m; j++) temp1[j] = max(dp[i-1][j], temp1[j-1]) + robot[i][j];
        for(int j = m-1; j >= 1; j--) temp2[j] = max(dp[i-1][j], temp2[j+1]) + robot[i][j];

        for(int j = 1; j <= m; j++) {
            dp[i][j] = max(temp1[j], temp2[j]);
        }
    }
    
    cout << dp[n][m];
}