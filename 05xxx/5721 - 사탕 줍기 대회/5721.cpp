#include <iostream> // BOJ 5721
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int n, m;
vector<vector<int>> candy, dp;

int solve() {
	vector<int> ret(MAX, 0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(j == 0) dp[i][j] = candy[i][j];
			else if(j == 1) dp[i][j] = max(dp[i][j-1], candy[i][j]);
			else dp[i][j] = max(dp[i][j-1], dp[i][j-2] + candy[i][j]);
		}
		if(i == 0) ret[i] = dp[i][m-1];
		else if(i == 1) ret[i] = max(dp[i-1][m-1], dp[i][m-1]);
		else ret[i] = max(ret[i-1], ret[i-2] + dp[i][m-1]);
	}
	return ret[n-1];
}

int main() {
	FASTIO
	
	while(cin >> n >> m) {
		if(n == 0 && m == 0) break;
		candy = vector<vector<int>>(n, vector<int>(m, 0));
		dp = vector<vector<int>>(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> candy[i][j];
		cout << solve() << "\n";
	}
}