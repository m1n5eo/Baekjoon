#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111

int n, temp;
vector<int> health(MAX, 0), happy(MAX, 0);
vector<vector<int>> dp(MAX, vector<int>(MAX, 0));

int solve() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 100; j++) {
			if(j-health[i] > 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-health[i]] + happy[i]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][100];
}

int main() {
	FASTIO
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> health[i];
	for(int i = 1; i <= n; i++) cin >> happy[i];
	cout << solve();
}