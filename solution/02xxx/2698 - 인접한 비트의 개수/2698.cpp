#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890
#define MAX 111

vector<vector<vector<int>>> dp(MAX, vector<vector<int>>(MAX, vector<int>(2, 0)));

void init() {
	dp[2][0][0] = 2;
	dp[2][0][1] = 1; dp[2][1][1] = 1;
	for(int i = 3; i < MAX; i++) {
		for(int j = 0; j < i; j++) {
			dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
			if(j > 0) dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j-1][1];
			else dp[i][j][1] = dp[i-1][j][0];
		}
	}
}

int solve() {
	int n, k;
	cin >> n >> k;
	return dp[n][k][0] + dp[n][k][1];
}

int main() {
	FASTIO
	init();
	int tc; cin >> tc;
	while(tc--) cout << solve() << "\n";
}