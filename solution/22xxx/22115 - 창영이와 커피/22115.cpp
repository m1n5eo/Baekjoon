#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890
#define MAX_N 111
#define MAX_M 111111

int n, k, temp;
vector<int> caffeine(1, 0);
vector<vector<int>> dp(MAX_N, vector<int>(MAX_M, INF));

int solve() {
	if(k == 0) return 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			if(j-caffeine[i] >= 0 && dp[i-1][j-caffeine[i]] != INF) dp[i][j] = min(dp[i][j], dp[i-1][j-caffeine[i]]+1);
			dp[i][j] = min(dp[i][j], dp[i-1][j]);
		}
	}
	return (dp[n][k] != INF? dp[n][k] : -1);
}

int main() {
	FASTIO

	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> temp;
		caffeine.push_back(temp);
		dp[i][temp] = 1;
	}

	cout << solve();
}