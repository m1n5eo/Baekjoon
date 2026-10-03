#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890
#define MAX 100001

int n, m, l, c;
vector<pair<int, int>> pipe(1, {0, 0});
vector<int> dp(MAX, 0);

int solve() {
	dp[0] = INF;
	for(int i = 1; i <= n; i++) for(int j = m; j >= 1; j--) if(j-pipe[i].first >= 0) dp[j] = max(dp[j], min(dp[j-pipe[i].first], pipe[i].second));
	return dp[m];
}

int main() {
	FASTIO

	cin >> m >> n;
	for(int i = 1; i <= n; i++) {
		cin >> l >> c;
		pipe.push_back({l, c});
	}

	cout << solve();
}